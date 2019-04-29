#include "../Inc/17-temp-temp-para.h"

//https://www.cnblogs.com/lsgxeva/p/7690080.html
//https://blog.csdn.net/qq_33762043/article/details/79674862

int main1() {
    man<std::string> man1("hello");  // 类模版实例化对象
    man1.printName();

    fprintMan(man1);  // 类模版的友元函数

    printClass<std::string> print1;  // 类模版的友元类
    print1.print(man1);

    printMan(man1);  // 类模版作为函数参数

    people<std::string, man> people1;
    people1.printPeople(man1);  // 类模版作为模版参数

    std::cout << addTemplate(3, 4) << std::endl;  // 函数模版实例化
    std::cout << addTemplate(7.7, 9.5) << std::endl;

    printAdd<int>(addTemplate, 10, 54);  // 函数模版必须实例化

    addclass<int> addclass1;
    addclass1.printAddFun(addTemplate, 10, 54);  // 函数模版作为类的参数

    system("pause");
    return 0;
}

int main() {
    ren<string> r("nihao");
    MyClass2<ren<string>> m(r);  //仅仅使用template<class T>
    People<string, ren> p(r);    //使用template<class T> class T1
    cout << m.t.name << endl;
    cout << p.r.name << endl;

    main1();
    return 0;
}