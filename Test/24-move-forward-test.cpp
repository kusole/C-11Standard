#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

template<typename T>
void PrintT(T &t) {
    cout << "lvalue" << endl;
}

template<typename T>
void PrintT(T &&t) {
    cout << "rvalue" << endl;
}

template<typename T>
void TestForward(T &&v) {
    PrintT(v);
    PrintT(forward<T>(v));
    PrintT(move(v));
}

class MyString {
  private:
    char *m_data;
    size_t m_len;
    void copy_data(const char *s) {
        m_data = new char[m_len + 1];
        memcpy(m_data, s, m_len);
        m_data[m_len] = '\0';
    }

  public:
    //构造函数
    MyString() {
        m_data = NULL;
        m_len = 0;
    }
    //构造函数
    MyString(const char *p) {
        m_len = strlen(p);
        copy_data(p);
    }
    //复制构造函数
    MyString(const MyString &str) {
        m_len = str.m_len;
        copy_data(str.m_data);
        cout << "copy constructor is called! source: " << m_data << endl;
    }
    //移动复制构造函数
    MyString(MyString &&str) {
        m_len = str.m_len;
        m_data = str.m_data;
        str.m_len = 0;
        str.m_data = NULL;
        cout << "Move constructor is called! source: " << m_data << endl;
    }
    //复制赋值函数
    MyString &operator=(const MyString &str) {
        if (this != &str) {
            m_len = str.m_len;
            if (m_data)
                delete []m_data;
            copy_data(str.m_data);
        }
        cout << "copy assignment is called! source: " << m_data << endl;
        return *this;
    }
    //移动赋值函数
    MyString &operator=(MyString &&str) {
        if (this != &str) {
            m_len = str.m_len;
            if (m_data)
                delete[]m_data;
            m_data = str.m_data;
            str.m_len = 0;
            str.m_data = NULL;
        }
        cout << "Move assignment is called! source: " << m_data << endl;
        return *this;
    }

    friend ostream &operator<<(ostream &output, const MyString &str) {
        output << str.m_data << endl;
        return output;
    }

    virtual ~MyString() {
        cout << "~MyString" << endl;
        if (m_data) {
            cout << "delete []mdata" << endl;
            delete[] m_data;
        }
    }
};

int main() {
    /*
        1为右值，所以未定义类型 T &&v 被右值初始化后变成右值引用
        此时T被命名为int，对已经命名的右值，在函数TestForward内部编译器当作左值
        所以PrinT(v)传入为左值，调用左值模板
        PrintT(forward<T>(v)) v被保持到右值
        PrintT(move(v)) v被转换到右值，实际上也为右值
    */
    // T 为 int
    TestForward(1); // l,r,r

    int x = 1;

    /*
        x为左值，未定义类型 T &&v 被左值初始化为左值引用
        此时T被命名为int，对已经命名的右值，在函数TestForward内部编译器当作左值
        所以PrinT(v)传入为左值，调用左值模板
        PrintT(forward<T>(v)) v被保持到左值
        PrintT(move(v)) v被转换到右值，实际上也为左值
    */
    // T 为 int &
    TestForward(x); // l,l,r

    /*
        forward的转换规则为:
            模板参数为引用类型T、T&&时，返回右值引用
            模板参数为引用类型T&时，返回左值引用。
        引用折叠：
            左值折叠到任何引用，返回左值引用
            右值折叠到右值引用，返回右值引用
    */
    TestForward(forward<int>(x)); // l,r,r
    TestForward(forward < int && > (x)); //l,r,r
    TestForward(forward<int &>(x)); //l,l,r

    MyString a;
    MyString b("world"); //构造函数

    a = MyString("hello"); //移动赋值，并会析构临时变量
    a = b; //普通赋值，不会析构临时变量
    a = move(b); //移动赋值，不会析构临时变量
    vector<MyString> vec;
    vec.reserve(10);
    vec.push_back(MyString("kusole"));//移动构造，并会析构临时对象
    vec.push_back(a);//复制构造

    vec.push_back(std::move(a));//移动构造，不会析构临时对象
    // cout << vec.size() << endl;
    // for (auto &a : vec) {
    //     cout << a << endl;
    // }

    //emplace_back减少内存拷贝和移动，可用直接通过参数来构建容器内的元素
    vec.emplace_back("good");
    return 0;
}

//https://blog.csdn.net/u012508160/article/details/79218936