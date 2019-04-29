#include "../Inc/18-variadic-template.h"
#include <bitset>
#include <vector>

int main() {
    //variadic template parameter
    print(7.5, "hello", bitset<16>(337), 42);
    //ranged-base for(since c++11)
    vector<double> d{1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
    //pass by value
    for (auto elem : d) {
        cout << elem << " ";
    }
    cout << endl;
    //pass by refer
    for (auto& elem : d) {
        elem *= 3;
    }
    for (auto& elem : d) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}