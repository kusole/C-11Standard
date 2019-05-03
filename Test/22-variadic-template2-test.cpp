#include "../Inc/22-variadic-template2.h"

int main() {
    //
    int *pi = new int;
    printfA("%d%s%p%f\n",
            10,
            "abc",
            pi,
            3.1415926
           );

    //
    // tuple<int, float, string> t{41, 6.3, "nico"};
    // std::cout << sizeof(t) << std::endl;
    // std::cout << t.head() << std::endl;
    // std::cout << t.tail().head() << std::endl;
    // std::cout << t.tail().tail().head() << std::endl;

    //
    // std::cout << make_tuple(1.5, "abc", 8, 10) << std::endl;
    return 0;
}
