#ifndef __07_VIRTUAL__
#define __07_VIRTUAL__
#include <iostream>
using namespace std;
class CDocument {
  public:
    void onFileOpen() {
        cout << "dialog..." << endl;
        cout << "check file status..." << endl;
        cout << "open file..." << endl;
        Serialize();
        cout << "close file..." << endl;
        cout << "update all views..." << endl;
    }
    virtual void Serialize() {};
};

class CMyDoc : public CDocument {
  public:
    virtual void Serialize() {
        cout << "CMyDoc::Serialize()" << endl;
    }
};

class CMyDoc1 : public CDocument {
  public:
    virtual void Serialize() {
        cout << "CMyDoc1::Serialize()" << endl;
    }
};
/*
    Template Method
            CDocument
                I
        CMyDoc.CmyDoc1...
    CDocument中实现大部分固定的操作，然后将关键不同操作设计为接口（虚函数）
    由派生类进行完成。
*/
#endif