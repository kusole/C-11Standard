#include <iostream>
using namespace std;
namespace detail_range {

//////////////
//the range iterator
//////////////
template<typename T>
class iterator {
  public:
    using value_type = T;
    using size_type = size_t;

  private:
    size_type cursor_;//迭代次数指针
    const value_type step_;//迭代步长
    value_type value_;//初始值

  public:
    iterator(size_type cur_start, value_type begin_val, value_type step_val):
        cursor_(cur_start), value_(begin_val), step_(step_val) {
        value_ += step_ * cursor_;//构造迭代器位置值value_;
    }
//重载operator* 用于去迭代器的值（*iterator）
    value_type operator*()const {
        return value_;
    }
//重载operator != 用于判断迭代器是否为比较值 例如：itertor != impl.end();
//比较迭代器当前指针指向是否和比较值相等
    bool operator !=(const iterator &rhs) const {
        return (cursor_ != rhs.cursor_);
    }
//重载operator++ 用于迭代器自加 例如： iterator++
//值加上一个步长
//迭代器指针向后移动一位
    iterator &operator++(void) {
        value_ += step_;
        ++cursor_;
        return (*this);
    }

};

template<typename T>
class impl {
  public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type &;
    //模板别名
    using iterator = detail_range::iterator<value_type>;
    using const_iterator = const detail_range::iterator<value_type>;
    using size_type = typename iterator::size_type;

  private:
    const value_type begin_;
    const value_type end_;
    const value_type step_;
    const size_type max_count_;

    size_type get_adjusted_count(void)const {
        if (step_ > 0 && begin_ >= end_)
            throw std::logic_error("End value must be greater than begin value.");
        else if (step_ < 0 && begin_ <= end_)
            throw std::logic_error("End value must be less than begin value.");

        size_type x = static_cast<size_type>((end_ - begin_) / step_);
        if (begin_ + (step_ * x) != end_) ++x;
        return x;
    }

  public:
    impl(value_type begin_val, value_type end_val, value_type step_val)
        : begin_(begin_val)
        , end_(end_val)
        , step_(step_val)
        , max_count_(get_adjusted_count())
    {}
//返回迭代器区间的大小size
    size_type size(void) const {
        return  max_count_;
    }
//__for_begin迭代器，用于指向迭代区间的第一个位置，包括：
//开始迭代位置0，开始迭代位置的值（初始值），迭代步长
    const_iterator begin(void) const {
        return {0, begin_, step_};
    }
//__for_end迭代器，用于指向迭代区间的最后一个位置，包括：
//最大迭代次数（结束迭代位置），最后一个位置的值为最大迭代次数*步长，迭代步长
    const_iterator end(void) const {
        return {max_count_, begin_, step_};
    }
};

}

//range外敷函数模板，用于实现外部使用的接口
template<typename T>
detail_range::impl<T> range(T end) {
    //列表初始化
    return {{}, end, 1};
}

template<typename T>
detail_range::impl<T> range(T begin, T end) {
    //列表初始化
    return {begin, end, 1};
}
//自动类型推导
template<typename T, typename U>
auto range(T begin, T end, U step)->detail_range::impl < decltype(begin + step) > {
    using r_t = detail_range::impl < decltype(begin + step) >;
    return r_t(begin, end, step);
}

int main() {
    // std::cout << "range('a','f'):";
    // for (auto i : range<char>('a', 'f')) {
    //     std::cout << " " << i;
    // }
    // std::cout << std::endl;

    cout << "Range(15):";
    for (int i : range(15)) { //[0,15)
        cout << " " << i;
    }

    cout << endl;
    cout << "Range(2,6):";
    for (auto i : range(2, 6)) { //[2,6)
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(10.5, 15.5):";
    for (auto i : range(10.5, 15.5)) { //[10.5,15.5),步长为1
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(35,27,-1):";
    for (int i : range(35, 27, -1)) { //(27, 35]，步长为-1
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(2,8,0.5):";
    for (auto i : range(2, 8, 0.5)) { //[2,8),步长为0.5
        cout << " " << i;
    }
    cout << endl;

    cout << "Range(8,7,-0.1):";
    for (auto i : range(8, 7, -0.1)) { //(7,8]，步长为-0.1
        cout << " " << i;
    }
    cout << endl;

    cout << "Range('a', 'z'):";
    for (auto i : range('a', 'z')) { //['a','z'),步长为1
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
