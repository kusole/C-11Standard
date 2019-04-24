#ifndef __05_SINGLETON__
#define __05_SINGLETON__
#include <iostream>
using namespace std;

// singleton
/*
    1.把构造函数、复制构造函数放在private中，让外部程序调用类的时候不能构造一个对象
    2.在privata中定义一个静态对象a。此时，类一旦编译好之后，就会在静态存储区有一个静态对象。
        由于构造函数为private。类一旦编译后，只存在一个对象，这样就形成了单例设计模式。
    3.由于对象为private类型的static对象，因此需要设计一个public的静态接口来供类外部程序调用
        接口设计为静态，然后返回静态对象a
    A::getInstance().setup();
*/

class A {
   public:
    static A &getInstance() {
        if (a == NULL) {
            a = new A();
        }
        return *a;
    }

    void setup() { cout << "单例模式" << this << endl; }

   private:
    A() {}
    A(const A &rhs) {}
    static A *a;
};
A *A::a = NULL;

// Meyers singleton
/*
    1.上述的方法存在一定的问题，无论有没有人需要用这个单例，农村中都会存在一个对象a
    2.我们需要设计的是当有人要调用getInstance()的时候，会创建一个static的单例
    3.可以把static A a.放入getInstance()函数中，至在调用的时候返回单例。
*/
class B {
   public:
    static B &getInstance();
    void setup() { cout << "改进单例模式" << this << endl; }

   private:
    B() {}
    B(const B &rhs) {}
};

B &B::getInstance() {
    static B b;
    return b;
}
#endif