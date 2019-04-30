#ifndef __15_TEMPLATE_SPECIA__
#define __15_TEMPLATE_SPECIA__
#include <cstring>
#include <iostream>
using namespace std;
/*
 *  函数模板特化
 *
*/
template <typename T>
T Max(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

typedef const char *CCP;
template <>
CCP Max<CCP>(CCP s1, CCP s2) {
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}
//函数重载
typedef const char *CCP;
CCP Max(CCP s1, CCP s2) {
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

/*
 *  类模板特化
 *
*/
template <typename T>
class A {
    T num;

  public:
    A() {
        num = T(6.6);
    }
    void print() {
        cout << "A' num:" << num << endl;
    }
};

template <>
class A<char *> {
    char *str;

  public:
    A() {
        str = "A' special definition ";
    }
    void print() {
        cout << str << endl;
    }
};

#endif
