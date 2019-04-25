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
    virtual void Serialize(){};
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

#endif