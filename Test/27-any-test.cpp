#include "../Inc/27-any.hpp"

int main() {
    Any n;
    auto r = n.IsNull();
    std::string s1 = "hello";
    n = s1;
    n.AnyCase<int> ();
    Any n1 = 1;
    n1.Is<int> ();
    return 0;
}