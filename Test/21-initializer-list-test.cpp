#include <iostream>
#include <vector>
using namespace std;

class Num {
  private:
    std::vector<int> vv;
  public:

    Num(const std::initializer_list<int> &v) {
        for (auto a : v) {
            vv.push_back(a);
        }
    }

    void PrintNum(void) {
        for (auto v : vv) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
};

template<typename T>
void output(initializer_list<T> lst) {
    for (auto &a : lst) {
        cout << a << endl;
    }
}

int main() {
    vector<int>a{1, 2, 3, 4, 5};
    // 或者std::vector<int>a{1,2,3,4,5};
    //未引入initializer_list之前为：
    // std::vector<int>a;
    // a.push_back(1);
    // a.push_back(2);
    // a.push_back(3);
    // a.push_back(4);
    // a.push_back(5);

    int c1{3};
    int c2 = {3};
    int c3 = 3.3; //这里会进行默认类型转换
    // int c4 = {3.3}; //这里编译器会给出警告（也有可能是错误）
    cout << c1 << " " << c2 << " " << c3 << " " << endl;

    //自定义类型使用initializer_list
    Num n{1, 2, 3, 4};
    n.PrintNum();

    //优雅的循环
    for (auto s : {
                1, 2, 3, 4, 5, 6
            }) {
        cout << s << endl;
    }

    //c++可变参数
    initializer_list<int> list{5, 6, 7, 8};
    output(list);
    output({1, 2, 3, 4});
    output({"how", "are", "you", "!"});
    int ia = 100;
    output ({1, 2, 3, ia});

    return 0;

}