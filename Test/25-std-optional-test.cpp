#include "../Inc/25-std-optional.hpp"

int main() {
    Optional<std::string> a("ok");
    Optional<std::string> b("ok");
    Optional<std::string> c("aa");
    std::cout << *a << std::endl;
    c = a;
    if (c < a)
        std::cout << "<" << std::endl;

    if (a == b)
        std::cout << "=" << std::endl;

    std::map<Optional<std::string>, int> mymap;
    mymap.insert(std::make_pair(a, 1));
    mymap.insert(std::make_pair(c, 2));

    auto it = mymap.find(a);
    std::cout << it->second << std::endl;
}
