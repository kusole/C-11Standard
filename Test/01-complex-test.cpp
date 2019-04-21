#include "../Inc/01-complex.h"
#include <iostream>

using namespace std;

int main() {
    complex<int> C1(2, 1);
    complex<int> C2 = C1;
    cout << C1 << endl;
    cout << C2 << endl;

    C2 = C2 + 2;
    cout << C2 << endl;
    C2 = 2 + C2;
    cout << C2 << endl;
    C2 = -C1;
    cout << C2 << endl;
    C2 += C1 += C1;
    cout << C2 << endl;
    cout << conj(C2) << endl;
    return 0;
}