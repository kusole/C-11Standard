#include "../Inc/04-account.h"

int main() {
    //调用static函数有两种方式：
    //(1)通过object调用 a.static_func();
    //(2)通过class name调用 class::static_func();
    Account::set_rate(5.0);

    Account a;
    a.set_rate(7.0);
    return 0;
}