#include <iostream>
#include <map>
#include <type_traits>

template<typename T>
class Optional {
    // 定义内存对齐的缓冲区类型
    // sizeof(T)表示模板类型的大小
    // aligned_of<T>::value表示内存对齐的大小
    using data_t = typename std::aligned_storage<sizeof(T), std::alignment_of<T>::value>::type;
  public:
    Optional(): m_hasInit(false) {}
    Optional(const T &v) { //const T&v 为万能引用类型
        Create(v);
    }
    Optional(T &&v): m_hasInit(false) { //移动构造函数  Optional A(string())
        Create(std::move(v));
    }
    Optional(const Optional &other): m_hasInit(false) {
        if (other.IsInit())
            Assign(other);
    }
    Optional(Optional &&other): m_hasInit(false) {
        if (other.IsInit()) {
            Assign(std::move(other));
            other.Destory();
        }
    }
    Optional &operator=(Optional &&other) {
        Assign(std::move(other));
        return *this;
    }

    Optional &operator=(const Optional &other) {
        Assign(other);
        return *this;
    }
    template<class... Args>
    void emplace(Args &&... args) {
        Destory();
        Create(std::forward<Args>(args)...);
    }
    explicit operator bool() const {
        return IsInit();
    }
    T &operator*() {
        return *((T *) (&m_data));
    }

    T const &operator*() const {
        if (IsInit()) {
            return *((T *) (&m_data));
        }
        throw std::logic_error("111");
    }
    bool IsInit()const {
        return m_hasInit;
    }
    bool operator == (const Optional<T> &rhs) const {
        return (!bool(*this)) != (!rhs) ? false : (!bool(*this) ? true : (*(*this)) == (*rhs));
    }

    bool operator < (const Optional<T> &rhs) const {
        return !rhs ? false : (!bool(*this) ? true : (*(*this) < (*rhs)));
    }

    bool operator != (const Optional<T> &rhs) {
        return !(*this == (rhs));
    }
    ~Optional() {
        Destory();
    }

  private:
    //通过右值引用与完美转发，消除拷贝参数args带来的性能消耗
    template<class... Args>
    void Create(Args &&... args) {
        new (&m_data) T(std::forward<Args>(args)...);//palce_ment new
        m_hasInit = true;   //标记为已经初始化
    }
    void Destory() {
        if (m_hasInit) {
            m_hasInit = false;
            ((T *)(&m_data))->~T();
        }
    }
    void Assign(const Optional &other) {
        if (other.IsInit()) {
            Copy(other.m_data);
            m_hasInit = true;
        } else {
            Destory();
        }
    }
    void Assign(Optional &&other) {
        if (other.IsInit()) {
            Move(std::move(other.m_data));
            m_hasInit = true;
            other.Destory();
        } else {
            Destory();
        }
    }
    void Copy(const data_t &val) {
        Destory();
        new (&m_data) T(*((T *)(&val)));
    }
    void Move(data_t &&val) {
        Destory();
        new (&m_data) T(std::move(*((T *)(&val))));
    }

  private:
    bool m_hasInit = false; //是否已经初始化
    data_t m_data;          //内存对齐缓冲区
};


// optional用途如其名，它可以容纳一个对象值或是为空。典型的应用情景是函数调用时，
// 如需根据条件返回一个对象（有效）或默认对象（无效），若该对象构造成本很高（资源分配等），
// 可用optional返回一个空对象，提高效率。
// 标准库的用法
//
// template <typename T>
// std::optional<T> getValueOptional(const std::size_t index, const std::vector<T> &values) {
//     if (index >= values.size())
//         return {};

//     auto it{ values.begin() };
//     std::advance(it, index);
//     return *it;
// }
// template <typename T>
// T getValue(const std::size_t index, const std::vector<T> &values)
// {
//     if (index >= values.size())
//         return T{};

//     auto it{ values.begin() };
//     std::advance(it, index);
//     return *it;
// }

// // test optional
// std::vector<int> values{ 1,2,3,4,5 };
// if (auto val{ getValueOptional(1, values) }) {
//     std::wcout << val.value() << std::endl;
// }