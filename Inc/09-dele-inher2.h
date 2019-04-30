#ifndef __09_DELE_INHER2__
#define __09_DELE_INHER2__

#include <iostream>
#include <vector>
using namespace std;

class Component {
    int value;

  public:
    Component(int val) : value(val) {}
    virtual void add(Component *) {};
    int get_val() const {
        return value;
    }
    virtual ~Component() {
        cout << "delete Component " << this->get_val() << endl;
    }
    virtual void show() {}
};

class Primitive : public Component {
  public:
    Primitive(int val) : Component(val) {}
    virtual ~Primitive() {
        cout << "delete Primitive " << this->get_val() << endl;
    }
};

class Composite : public Component {
    vector<Component *> c;

  public:
    Composite(int val) : Component(val) {}
    void add(Component *elem) {
        c.push_back(elem);
    }
    void show() {
        cout << "目录 " << this->get_val() << " 包括以下文件和目录： " << endl;
        for (int i = 0; i < c.size(); i++) {
            cout << c[i]->get_val() << " ";
        }
        cout << endl;
    }
    virtual ~Composite() {
        cout << "delete Composite " << this->get_val() << endl;
    }
};
/* 组合模式
            Component <-----n---I
                I               I
    Primitive       Composite ^-I
                    vector<Component*>

    可以理解为Component为文件系统，包括文件和目录
    Primitive为文件
    Composite为目录，目录里面可以包括目录和文件，即包含Component
*/
#endif