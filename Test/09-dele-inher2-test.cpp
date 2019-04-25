#include "../Inc/09-dele-inher2.h"

int main() {
    Component *p0 = new Composite(0);
    Component *p1 = new Primitive(1);
    Component *p2 = new Primitive(2);
    Component *p3 = new Composite(3);
    Component *p4 = new Primitive(4);
    p0->add(p1);
    p0->add(p2);
    p0->add(p3);
    p3->add(p4);
    p0->show();
    p3->show();
    delete p0;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}