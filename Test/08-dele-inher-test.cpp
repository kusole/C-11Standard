#include "../Inc/08-dele-inher.h"

int main() {
    Subject S;
    Observer *p1 = new myObserver;
    Observer *p2 = new myObserver;
    Observer *p3 = new myObserver;
    S.attach(p1);
    S.attach(p2);
    S.attach(p3);
    S.set_val(1);
    S.set_val(2);
    delete p1;
    delete p2;
    delete p3;
    return 0;
}