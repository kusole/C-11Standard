#ifndef __17_TEMP_TEMP_PARA__
#define __17_TEMP_TEMP_PARA__

#include <iostream>
#include <string>
using namespace std;

//类模板当作一个类的参数
//设计STL时候用到
//面试，类模板当作参数

class MyClass {
   public:
   private:
};
template <typename T>
class MyClass2 {
   public:
    T t;
    MyClass2(T t1) : t(t1) {}

   private:
};

template <typename T>
class ren  //一个通用的类的类模板
{
   public:
    T name;
    ren(T t) : name(t) {}
};

template <typename T1, template <typename T> class T2>  //使用类模板当作模板参数的类
class People {
   public:
    T2<T1> r;
    People(T2<T1> t1) : r(t1) {}
};

/////////////////////////////////////////exp2
// 类模版
template <typename T>
class man {
   public:
    man(T t) : name(t) {
    }

    void printName() {
        std::cout << name << std::endl;
    }

    // 类模版的友元函数声明
    template <typename Q>
    friend void fprintMan(man<Q>& m);

    // 类模版的友元类声明
    template <typename Q>
    friend class printClass;

   private:
    T name;
};

// 类模版的友元函数定义
template <typename Q>
void fprintMan(man<Q>& m)  // 注意: 模板类必须实例化 内部实例化 man<Q>
{
    m.printName();
}

// 类模版的友元类定义
template <typename Q>
class printClass {
   public:
    void print(man<Q>& my)  // 注意: 模板类必须实例化 内部实例化 man<Q>
    {
        my.printName();
    }
};

// 类模版作为函数参数
template <typename T>
void printMan(man<T>& m)  // 注意: 模板类必须实例化 内部实例化 man<T>
{
    m.printName();
}

// 类模版作为模版参数
template <typename T1, template <typename T> class T2>
class people {
   public:
    void printPeople(T2<T1> t1)  // 注意: 模板类必须实例化 内部实例化 T2<T1>
    {
        t1.printName();
    }
};

// 函数模版
template <typename T>
T addTemplate(T x, T y) {
    return (x + y);
}

// 函数模版作为函数的参数
template <typename T>
void printAdd(T (*p)(T, T), T x, T y)  // 注意: 模版函数的指针必须实例化 外部实例化
{
    std::cout << (*p)(x, y) << std::endl;
}

// 函数模版作为类的参数
template <typename T>
class addclass {
   public:
    void printAddFun(T (*p)(T, T), T x, T y)  // 注意: 模版函数的指针必须实例化 外部实例化
    {
        std::cout << (*p)(x, y) << std::endl;
    }
};

#endif