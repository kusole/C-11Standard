#ifndef __18_VARIADIC_TEMPLATE__
#define __18_VARIADIC_TEMPLATE__

#include <iostream>
using namespace std;

void print() {
    //用于最后一个参数调用，其他递归调用下面的自己
}

template <typename T, typename... Types>
void print(const T &firstArg, const Types &... args) {
    cout << firstArg;
    cout << "\t还剩下参数个数为： " << sizeof...(args) << endl;
    print(args...);
}

#endif
