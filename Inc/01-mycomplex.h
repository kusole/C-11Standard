#ifndef __01_MYCOMPLEX__
#define __01_MYCOMPLEX__
#include <cmath>
#include <iostream>
using namespace std;

template <typename T> class myComplex;
template <typename T>
myComplex<T> &__doadp(myComplex<T> *ths, const myComplex<T> &r);
template <typename T>
myComplex<T> operator+(const myComplex<T> &obj1, const myComplex<T> &obj2);
template <typename T>
myComplex<T> operator+(const T a, const myComplex<T> &obj1);
template <typename T>
myComplex<T> operator+(const myComplex<T> &obj1, const T a);
template <typename T> myComplex<T> operator-(const myComplex<T> &r);
template <typename T>
bool operator==(const myComplex<T> &obj1, const myComplex<T> &obj2);
template <typename T>
bool operator!=(const myComplex<T> &obj1, const myComplex<T> &obj2);
template <typename T>
ostream &operator<<(ostream &output, const myComplex<T> &r);
template <typename T> myComplex<T> conj(const myComplex<T> &r);

template <typename T> class myComplex {
  public:
    myComplex(T r, T i) : re(r), im(i) {}
    myComplex(const myComplex<T> &r) {
        this->re = r.re;
        this->im = r.im;
    }

    T real() const {
        return re;
    }
    T imag() const {
        return im;
    }

    myComplex<T> &operator+=(const myComplex<T> &r);
    myComplex<T> &operator=(const myComplex<T> &r);
    myComplex<T> &operator++();
    myComplex<T> operator++(int);
    friend myComplex<T> operator+
    <>(const myComplex<T> &obj1, const myComplex<T> &obj2);
    friend myComplex<T> operator+<>(const T a, const myComplex<T> &obj1);
    friend myComplex<T> operator+<>(const myComplex<T> &obj1, const T a);
    friend myComplex<T> operator-<>(const myComplex<T> &r);
    friend bool operator==
    <>(const myComplex<T> &obj1, const myComplex<T> &obj2);
    friend bool operator!=
    <>(const myComplex<T> &obj1, const myComplex<T> &obj2);
    friend ostream &operator<<< > (ostream &output, const myComplex<T> &r);
    friend myComplex<T> conj<>(const myComplex<T> &r);


  private:
    T re;
    T im;
    friend myComplex<T> &__doadp<>(myComplex<T> *ths, const myComplex<T> &r);
};

#endif