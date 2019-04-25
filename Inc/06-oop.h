#ifndef __01_OOP__
#define __01_OOP__

#include <iostream>
using namespace std;
//composition 复合
class B {
   public:
    B() : b() { cout << "construct a object B!!!" << endl; }
    ~B() { cout << "destruct a object B!!!" << endl; }

   private:
    int b;
};

class A {
   public:
    A() { cout << "construct a object A!!!" << endl; }
    ~A() { cout << "destruct a object A!!!" << endl; }

   private:
    B c;
    int a;
};

//委托 composition by referrence

class stringRep {
    friend class sstring;

   public:
    stringRep() : count_n(0) { cout << "construct a objectStringRep" << endl; }
    ~stringRep() { cout << "destruct a objectStringRep" << endl; }
    stringRep(char* chr) : count_n(0) {
        this->chr = chr;
        cout << "construct a objectStringRep" << endl;
    }
    char* getchr() const { return chr; }
    int get_n() const { return count_n; }

   private:
    int count_n;
    char* chr;
};

class sstring {
   public:
    sstring() { cout << "construct a objectSTRING" << endl; }
    sstring(stringRep& sr) : rep(&sr) {
        rep->count_n++;
        cout << "construct a objectSTRING, count = " << rep->count_n << endl;
    }
    ~sstring() {
        rep->count_n--;
        cout << "construct a objectString, count = " << rep->count_n << endl;
    }

   private:
    stringRep* rep;
};

class C
{
public:
    C(){cout<<"construct a objectC"<<endl;}
    ~C(){cout<<"destruct a objectC"<<endl;}
};

class D:public C
{
public:
    D(){cout<<"construct a objectD"<<endl;}
    ~D(){cout<<"destruct a objectD"<<endl;}
};

#endif