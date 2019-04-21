#include "../Inc/01-mycomplex.hpp"
#include <iostream>

using namespace std;

int main() {
    myComplex<int> C1(1,2);
    myComplex<int> C2 = C1;    

    C1+=C2+=C2;
    C1 = C2;
    C1 = -C2;
    C1 = C1 + 2;
    C1 = 2 + C1;
    myComplex<int> C3 = C1++;
    ++C1;
    return 0;
}