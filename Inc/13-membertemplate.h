#ifndef __13_MEMBERTEMPLATE__
#define __13_MEMBERTEMPLATE__

template <class T1, class T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair() : first(T1()), second(T2()) {}
    pair(const T1 &a, const T2 &b) : first(a), second(b) {}

    template <class U1, class U2>
    pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}
};

class Base1 {};
class Drived1 : public Base1 {};

class Base2 {};
class Drived2 : public Base2 {};

/*
template <typename _Tp>
class share_ptr : public __share_ptr<_Tp> {
    tempate<typename _Tp1> explicit shared_ptr(_Tp1* __p) : __share_ptr<_Tp>(__p) {}
};
Base1 *ptr = new Derived1; //up-case;
share_ptr<Base1> sptr(new Derived1);  //模拟upcase;
*/
#endif