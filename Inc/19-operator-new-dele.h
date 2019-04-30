#ifndef __19_OPERATOR_NEW_DELE__
#define __19_OPERATOR_NEW_DELE__
#include <iostream>
using namespace std;
/*
    Foo *p = new Foo;
    ==>
        try{
            void *mem = operator new(sizeof(Foo));
            p = static_case<Foo*>(mem);
            p->Foo::Foo();
        }

    delete *p
    ==>
        p->~Foo();
        operator delete(p);
*/

class Foo {
  public:
    int _id;
    long _data;
    string _str;
  public:
    Foo(): _id(0) {
        cout << "default ctor.this = " << this << " id = " << _id << endl;
    }
    Foo(int i): _id(i) {
        cout << "ctor.this = " << this << " id = " << _id << endl;
    }
    ~Foo() {
        cout << "dtor.this = " << this << " id = " << _id << endl;
    }
    static void *operator new (size_t size);
    static void operator delete (void *pdead, size_t size);
    static void *operator new[](size_t size);
    static void operator delete[](void *pdead, size_t size);
};

void *Foo::operator new (size_t size) {
    Foo *p = (Foo *)malloc(size);
    cout << "operator new, size = " << size << endl;
    return p;
}

void Foo::operator delete (void *pdead, size_t size) {
    cout << "operator delete, size = " << size << endl;
    free(pdead);
}

void *Foo::operator new[](size_t size) {
    Foo *p = (Foo *)malloc(size);
    cout << "operator new[], size = " << size << endl;
    return p;
}

void Foo::operator delete[](void *pdead, size_t size) {
    cout << "operator delete[], size = " << size << endl;
    free (pdead);
}

#endif