#ifndef __08_DELE_INHER__
#define __08_DELE_INHER__

#include <iostream>
#include <vector>
using namespace std;

class Subject;

class Observer {
  public:
    virtual void update(Subject *sub, int value) = 0;
    virtual ~Observer() {
        cout << "decondutor Observer!!!" << endl;
    }
};

class Subject {
    int mValue;
    vector<Observer *> mViews;

  public:
    void attach(Observer *obs) {
        mViews.push_back(obs);
    }
    void set_val(int value) {
        mValue = value;
        notify();
    }
    void notify() {
        for (int i = 0; i < mViews.size(); i++) {
            mViews[i]->update(this, mValue);
        }
    }
    ~Subject() {
        cout << "decondutor subject!!!" << endl;
        // for (int i = 0; i < mViews.size(); i++) {
        //     delete mViews[i];
        // }
    }
};

class myObserver : public Observer {
  public:
    virtual void update(Subject *sub, int value) {
        cout << sub << " set value = " << value << endl;
    }
    ~myObserver() {
        cout << "deconductor myObserver!!!" << endl;
    };
};
/*
    Subject ^-> Observer
                    I
         myObserver1,myObserver2...
    观察者模式，也被称为发布订阅模式，一旦Subject发生改变，立即把改变发送给observer.
    其中Subject有Observer指针向量，用于指向Observer派生类，通知发送变化。
*/
#endif