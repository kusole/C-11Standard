#include "../Inc/12-functemplate.h"

int main() {
    stone r1(2, 3), r2(3, 3), r3;
    //函数模板在使用的时候不用指明template T.
    //min<stone>(r1,r2);
    r3 = min(r1, r2);
    return 0;
}