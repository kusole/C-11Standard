#include "../Inc/02-name.h"

int main() {
    Name C1("aaaaaaaaaaaa");
    Name C2 = C1;
    Name C3("bb");
    C1.printName();
    C2.printName();
    C3.printName();
    C3 = C2;
    C3.printName();
    return 0;
}