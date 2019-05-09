#include "../Inc/26-lazy.hpp"
void TestLazy() {

    //带参数的普通函数
    int y = 4;
    auto lazyer1 = lazy(Foo, y);
    std::cout << lazyer1.Value() << std::endl;

    //不带参数的lambda
    Lazy<int> lazyer2 = lazy([] {return 12; });
    std::cout << lazyer2.Value() << std::endl;

    //带参数的function
    std::function<int(int)> f = [](int x) {
        return x + 3;
    };
    auto lazyer3 = lazy(f, 3);
    std::cout << lazyer3.Value() << std::endl;

    //延迟加载大对象
    MyStruct t;
    t.Load();
}

int main() {
    TestLazy();
    return 0;
}