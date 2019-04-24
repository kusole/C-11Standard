#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    std::sort(v1.begin(), v1.end(), std::greater<int>());
    for (auto &&val : v1) {
        std::cout << val << ' ';
    }

    std::cout << std::endl;
    auto printStr = [](std::string_view str) {
        std::cout << str << std::endl;
    };
    printStr("Nice shot!");

    std::cout << "hello cpp!" << std::endl;
    return 0;
}