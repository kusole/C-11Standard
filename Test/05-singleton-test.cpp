#include "../Inc/05-singleton.h"

int main() {
    A::getInstance().setup();
    A::getInstance().setup();
    B::getInstance().setup();
    B::getInstance().setup();
    return 0;
}