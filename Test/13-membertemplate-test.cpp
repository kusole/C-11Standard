#include "../Inc/13-membertemplate.h"

int main() {
    Drived1 d1;
    Drived2 d2;

    pair<Drived1, Drived2> p1(d1, d2);
    pair<Base1, Base2> p2(p1);

    return 0;
}