#include "../Inc/16-partial-specia.h"

int main() {
    int a = 10;
    Test<double, double> t1(0.1, 0.2);
    Test<int, char> t2(1, 'A');
    Test<char, bool> t3('A', true);
    Test<int*, int*> t4(&a, &a);
    Test<const int, const int> t5(1, 2);

    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 5, 6};
    Test<vector<int>, vector<int>> t6(v1, v2);
    return 0;
}