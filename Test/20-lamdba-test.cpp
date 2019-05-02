#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    //最简单的lamdba
    [] {
        cout << "hello lamdba" << endl;
    }();

    //重新定义
    auto L1 = [] {
        cout << "hello lamba L1" << endl;
    };
    L1();

    //获取外部变量 by value
    int id = 0;
    auto L2 = [id] ()mutable{
        cout << "id = " << id << endl;
        ++id;
    };
    id = 20;
    L2();
    L2();
    L2();

    //获取外部变量 by reference
    auto L3 = [&id]()mutable{
        cout << "id = " << id << endl;
        ++id;
    };
    id = 10;
    L3();
    L3();
    L3();

    //带参数
    auto L4 = [&id](int parm)mutable{
        cout << "id = " << id << endl;
        cout << "parm = " << parm << endl;
        ++id;
    };
    id = 10;
    L4(7);
    L4(8);
    L4(9);

    //有返回值
    auto L5 = [&id](int parm)mutable{
        cout << "id = " << id << endl;
        cout << "parm = " << parm << endl;
        return id + parm;
    };
    id = 10;
    int temp = L5(9);
    cout << "tmp = " << temp << endl;

    //简化代码
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 2;
    int y = 9;
    vi.erase(remove_if(vi.begin(), vi.end(), [x, y](int n) {
        return x <= n && n <= y;
    }), vi.end());
    for (auto i : vi)
        cout << i << endl;
    /*
    class ABC_Test_14 {
      public:
        ABC_Test_14(int a, int b) : m_a(a), m_b(b) {}
        bool operator()(int n) const {
            return m_a < n && n < m_b;
        }

      private:
        int m_a;
        int m_b;
    };
    ...
    vi.erase(remove_if(vi.begin(), vi.end(), ABC_Test_14(x, y)), vi.end());
    */
    return 0;
}