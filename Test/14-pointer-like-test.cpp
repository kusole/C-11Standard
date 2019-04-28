#include "../Inc/14-point-like.h"
/*
point-like class常见的为智能指针和迭代器
1.shared_ptr<Foo> sp(new Foo);
2.List<Foo>::iterator ite;
具体见stl源码剖析
*/
int main() {
    shared_ptr<Foo> sp(new Foo);
    Foo f1(*sp);
    std::cout << f1.num << " " << (*sp).num << std::endl;
    sp->method();
    return 0;
}
