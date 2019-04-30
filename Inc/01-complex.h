#ifndef __01_COMPLEX__
#define __01_COMPLEX__
//防卫式申明，相同的包含不会编译两次导致错误
#include <cmath>
#include <iostream>
using namespace std;

//前置声明模版类
template <typename T> class complex;

//前置声明--友元函数的前置声明
template <typename T> ostream &operator<<(ostream &, const complex<T> &);

template <typename T>
complex<T> operator+(const complex<T> &, const complex<T> &);

template <typename T> complex<T> operator+(const complex<T> &, T);

template <typename T> complex<T> operator+(T, const complex<T> &);

template <typename T> complex<T> &__doapl(complex<T> *, const complex<T> &);

template <typename T> bool operator==(const complex<T> &, const complex<T> &);

template <typename T> bool operator!=(const complex<T> &, const complex<T> &);

template <typename T> complex<T> operator-(complex<T> &);

template <typename T> complex<T> conj(const complex<T> &);

template <typename T> class complex {
  public:
    /*
    1.构造方法分为(initialization list, 初始化列表)(assignments，赋值)
        两者的区别在于前者为构造函数初始化的时候就给变量赋初值
        后者为没有初始化，之后再赋值给变量，效率相对较低
    */
    complex(T r = 0, T i = 0) : re(r), im(i) {}
    /*
    2.构造函数重载(函数名称相同、函数传入参数不同、参数类型不同、返回值不同)
        complex() : re(0), im(0) {}
        为错误的写法，当运行下面代码时候
        complex<int> C1;
        complex<int> C2();
      由于前面的构造函数为带默认形参的，会与无参数构造函数冲突
    */
    complex(complex &r) {
        this->re = r.re;
        this->im = r.im;
    }
    /*
    3.pass by value vs. pass by reference(to const)
      a.普通类型，以int a为例：
        void myfun(int a)    //传值，产生复制
        void myfun(int& a)   //传引用，不产生复制
        void myfun(int* a)   //传地址，产生复制，本质上是一种传值，这个值是地址
      b.指针类型，以int* a为例：
        void myfun(int* a)   //传值，产生复制
        void myfun(int*& a)  //传引用，不产生复制
        void myfun(int**
    a)//传地址，产生复制，本质上是一种传值，这个值是指针的地址
      c.数组类型，以inta[10]为例：
        void myfun(int a[], int n) //传值，产生复制
        void myfun(int* a,int n) //传值，产生复制，传递的数组首地址
        void myfun(int (&arr)[10])//传引用，不产生复制。需要硬编码数组长度
        template<size_t size> void myfun(int (&arr)[size])
    //传引用，不产生复制。不需要硬编码数组长度
      full-ref:https://www.cnblogs.com/zjutzz/p/6818799.html
      d.const修饰
        const int a; a是一个常整型数
        int const a; a是一个常整型数
        const int *a; a是一个指向常整型数的指针，整型数是不可修改的，但指针可以
        int * const a;
    a为指向整型数的常指针，指针指向的整型数可以修改，但指针是不可修改的 int
    const * a const;
    a是一个指向常整型数的常指针，指针指向的整型数是不可修改的，同时指针也是不可修改的
    4.return  by value vs. return by reference(to const)

    */
    complex<T> &operator+=(const complex<T> &r);
    // complex<T> &operator+=(T a);

    friend complex<T> operator-<>(complex<T> &r);

    friend ostream &operator<<< > (ostream &output, const complex<T> &r);
    friend complex<T> operator+
    <>(const complex<T> &obj1, const complex<T> &obj2);
    friend complex<T> operator+<>(const complex<T> &obj1, T a);
    friend complex<T> operator+<>(T a, const complex<T> &obj1);
    friend bool operator==<>(const complex<T> &obj1, const complex<T> &obj2);
    friend bool operator!=<>(const complex<T> &obj1, const complex<T> &obj2);
    friend complex<T> conj <>(const complex<T> &r);
    /*
    4.const member functions(常成员函数)
      不改变函数体里面的变量
      定义const complex C1(2,1);
          C1.real();
          其中的real函数必须为const函数，否则发生编译错误；
          原因为const对象的值不能改变，如果调用非const成员函数可能会改变里面的值
    */
    const T &real() const {
        return re;
    }
    // T real(T r) {re = r;}
    const T &imag() const {
        return im;
    }

  private:
    /*
    1.complex(){};
    构造函数放在Private中不能被调用，单例模式为典型应用
    具体见：
    */
    T re, im;

    /*
    2.友元函数和友元类
      full-ref:http://www.runoob.com/cplusplus/cpp-friend-functions.html
      类模版和友元模版函数
      full-ref:https://www.jianshu.com/p/70ca94872418
    */

    friend complex<T> &__doapl<>(complex<T> *ths, const complex<T> &r);

    /*
    3.相同的class的各个objects互为friends
      complex C1(2,1);
      complex C2;
      C2.func(C1);
    */
    int func(const complex &param) {
        return param.re + param.im;
    }
};

template <typename T>
inline complex<T> &__doapl(complex<T> *ths, const complex<T> &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
template <typename T>
inline complex<T> &complex<T>::operator+=(const complex<T> &r) {
    return __doapl(this, r);
}
// template <typename T> inline complex<T> &complex<T>::operator+=(complex<T>
// &obj1,T a) {
//     obj1.re += a;
//     return *obj1;
// }
template <typename T>
ostream &operator<<(ostream &output, const complex<T> &r) {
    // output << r.re << " " << r.im;
    output << r.real() << " " << r.imag();
    return output;
}
template <typename T>
complex<T> operator+(const complex<T> &obj1, const complex<T> &obj2) {
    // complex<T> cls;
    // cls.re = obj1.re + obj2.re;
    // cls.im = obj1.im + obj2.im;
    return complex<T>(obj1.real() + obj2.real(), obj1.imag() + obj2.imag());
}
template <typename T> complex<T> operator+(const complex<T> &obj1, T a) {
    // complex<T> cls;
    // cls.re = obj1.re + a;

    return complex<T>(obj1.real() + a, obj1.imag());
}
template <typename T> complex<T> operator+(T a, const complex<T> &obj1) {
    // complex<T> cls;
    // cls.re = obj1.re + a;
    return complex<T>(obj1.real() + a, obj1.imag());
}
template <typename T>
bool operator==(const complex<T> &obj1, const complex<T> &obj2) {
    // return obj1.im == obj2.im && obj1.re == obj2.re;
    return obj1.imag() == obj2.imag() && obj1.real() == obj2.real();
}
template <typename T>
bool operator!=(const complex<T> &obj1, const complex<T> &obj2) {
    // return obj1.im != obj2.im || obj1.re != obj2.re;
    return obj1.imag() != obj2.imag() || obj1.real() != obj2.real();
}

template <typename T> complex<T> operator-(complex<T> &r) {
    complex<T> cls(-r.real(), -r.imag());
    return cls;
}
template <typename T> complex<T> conj(const complex<T> &r) {
    return complex<T>(r.real(), -r.imag());
}
#endif
