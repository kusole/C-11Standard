#ifndef __22_VARIADIC_TEMPLATE__
#define __22_VARIADIC_TEMPLATE__

#include <iostream>
#include <string>

//Variadic Templates 实现类似于 printf()的 函数
void printfA(const char *s) {
    while (*s) {
        if (*s == '%' && *(++s) != '%')
            throw std::runtime_error("invalid format string: missing arguments");
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void printfA(const char *s, T value, Args... args) {
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            std::cout << value << std::endl;
            printfA(++s, args...);// call even when *s == 0 to detect extra arguments
            return;
        }
        std::cout << *s++ << std::endl;
    }
    throw std::logic_error("extra arguments provided to printf");
}

//Variadic Templates 递归创建,递归继承
// template<typename Head, typename...Tail>
// class tuple<Head, Tail...>: private tuple<Tail...> {
//     typedef tuple<Tail...> inherited;
//   protected:
//     Head m_head;
//   public:
//     tuple() {}
//     tuple(Head v, Tail... vtail): m_head(v), inherited(vtail...) {} //inheriter(vtail...)调用父类的构造函数
//     auto head()->decltype(m_head) {
//         return m_head;
//     }// Head head() { return m_head;}
//     inherited &tail() {
//         return *this;
//     }
// };

//sizeof...(args)的使用
// template <int IDX, int MAX, typename... Args>
// struct PRINT_TUPLE {
//     static void print (ostream &os, const tuple<Args...> &t) {
//         os << get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
//         PRINT_TUPLE < IDX + 1, MAX, Args... >::print(os, t);
//     }
// };
// // partial specialization to end the recursion
// template <int MAX, typename... Args>
// struct PRINT_TUPLE<MAX, MAX, Args...>   {
//     static void print (std::ostream &os, const tuple<Args...> &t)  {
//     }
// };
// // output operator for tuples
// template <typename... Args>
// ostream &operator<< (ostream &os,
//                      const tuple<Args...> &t) {
//     os << "[";
//     PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t); //sizeof...(args) 会获取参数个数
//     return os << "]";
// }

#endif
