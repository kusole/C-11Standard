#include "../Inc/06-oop.h"

int main_composition() {
    A a;
    return 0;
}

int main_compositionByReference() {
    stringRep sr("never give up!!!");
    sstring str1(sr);
    sstring str2(sr);
    sstring str3(sr);
    cout << endl
         << "count_n=" << sr.get_n() << endl
         << endl;
    cout << sr.getchr() << endl
         << endl;
    return 0;
}

int main_inheritance(){
    D d;
    return 0;
}

int main() {
    main_composition();
    main_compositionByReference();
    main_inheritance();
    return 0;
}