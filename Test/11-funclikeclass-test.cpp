#include "../Inc/11-funclikeclass.h"
#include <iostream>

int main() {
    pair<int, double> myPair(1, 1.1);

    identity<int> myid;
    std::cout << myid(100) << std::endl;

    select1st<pair<int, double>> mysel1;
    std::cout << mysel1(myPair) << std::endl;

    select2nd<pair<int, double>> mysel2;
    std::cout << mysel2(myPair) << std::endl;

    less<int> myless;
    std::cout << myless(10, 2) << std::endl;

    return 0;
}