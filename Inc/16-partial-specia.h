#ifndef __16_PARTIAL_SPECIA__
#define __16_PARTIAL_SPECIA__
#include <iostream>
#include <vector>
using namespace std;
/*
template<class T1, class T2>      // 普通版本，有两个模板参数
class B { ..... };

template<class T2>　　　         // 偏特化版本，指定其中一个参数，即指定了部分类型
class B<int , T2> { ..... };　　// 当实例化时的第一个参数为int 则会优先调用这个版本
*/

/*
template<class T>     // 普通版本
class B { ..... };

template<class T>　　　//这个偏特化版本只接收指针类型的模板实参
class B<T*> { ..... };

template<class T>
class B<T&> { ..... };     // 这个偏特化版本只接受引用类型的模板实参
*/

/*
template<class T>    //普通版本
class B { ..... };

template<class T>　　　// 这种只接受用T实例化的vector的模板实参．也是一种偏特化
class B<vector<T>> { ......  };
*/
template <typename T1, typename T2>
class Test {
  public:
    Test(T1 i, T2 j) : a(i), b(j) {
        cout << "模板类" << endl;
    }

  private:
    T1 a;
    T2 b;
};

template <>  //全特化，由于是全特化，参数都指定了，参数列表故为空。
class Test<int, char> {
  public:
    Test(int i, char j) : a(i), b(j) {
        cout << "全特化" << endl;
    }

  private:
    int a;
    int b;
};

template <typename T2>  //由于只指定了一部分参数，剩下的未指定的需在参数列表中，否则报错。
class Test<char, T2> {
  public:
    Test(char i, T2 j) : a(j), b(j) {
        cout << "个数偏特化" << endl;
    }

  private:
    char a;
    T2 b;
};

template <typename T1, typename T2>  //这是范围上的偏特化
class Test<T1 *, T2 *> {
  public:
    Test(T1 *i, T2 *j) : a(i), b(j) {
        cout << "指针偏特化" << endl;
    }

  private:
    T1 *a;
    T2 *b;
};

template <typename T1, typename T2>  //同理这也是范围上的偏特化
class Test<T1 const, T2 const> {
  public:
    Test(T1 i, T2 j) : a(i), b(j) {
        cout << "const偏特化" << endl;
    }

  private:
    T1 a;
    T2 b;
};

template <typename T1, typename T2>
class Test<vector<T1>, vector<T2>> {
  public:
    Test(vector<T1> &i, vector<T2> &j) : a(i), b(j) {
        cout << "vector偏特化" << endl;
    }

  private:
    vector<T1> a;
    vector<T2> b;
};

#endif