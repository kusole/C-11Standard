#include "../Inc/19-operator-new-dele.h"

int main() {
    Foo *pf0 = new Foo(0);
    delete pf0;
    Foo *pf1 = ::new Foo(1);
    ::delete pf1;

    Foo *pf2 = new Foo[5];
    delete []pf2;

    return 0;
}