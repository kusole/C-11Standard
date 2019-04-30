#include "../Inc/15-template-special.h"

int main() {
    //调用实例：int Max<int>(int,int)
    int i = Max(10, 5);
    //调用显示特化：const char* Max<const char*>(const char*,const char*)
    const char *p = Max<const char *>("very", "good");
    //隐式调用特化，有函数重载优先调用函数重载
    const char *q = Max("very", "good");
    /*
    （1）如果使用普通重载函数，那么不管是否发生实际的函数调用，
    都会在目标文件中生成该函数的二进制代码。而如果使用模板的特化版本，
    除非发生函数调用，否则不会在目标文件中包含特化模板函数的二进制代码。
    这符合函数模板的“惰性实例化”准则。
    （2）如果使用普通重载函数，那么在分离编译模式下，应该在各个源文件中
    包含重载函数的申明，否则在某些原文件中就会使用模板实例化，而不是重载函数。
    */
    A<int> a1;  //显示模板实参的隐式实例化
    a1.print();
    A<char *> a2; //使用特化的类模板
    a2.print();
    return 0;
}