#ifndef __14_POINT_LIKE__
#define __14_POINT_LIKE__
#include <iostream>

template <class T>
class shared_ptr {
  public:
    shared_ptr(T *p) : px(p) {}
    T &operator*() const {
        return *px;
    }
    T *operator->() const {
        return px;
    }

  private:
    T *px;
};

struct Foo {
    int num = 3;
    Foo() {}
    Foo(Foo &f) : num(f.num) {}
    void method(void) {
        std::cout << "yes, u call it!" << std::endl;
    }
};

#endif