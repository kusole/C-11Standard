#include "../Inc/27-any.hpp"

int main() {
    Any n;
    auto r = n.IsNull();
    std::string s1 = "hello";
    std::string s2 = "world";
    n = s1;
    cout << n.AnyCase<string> () << endl;
    n = s2;
    cout << n.AnyCase<string> () << endl;
    Any n1 = 1;
    n1.Is<int> ();
    return 0;
}