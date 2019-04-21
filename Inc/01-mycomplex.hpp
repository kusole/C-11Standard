#include "01-mycomplex.h"

template <typename T>
inline myComplex<T> &__doadp(myComplex<T> *ths, const myComplex<T> &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
template <typename T>
inline myComplex<T> &myComplex<T>::operator+=(const myComplex<T> &r) {
    return __doadp(this, r);
}
template <typename T>
inline myComplex<T> &myComplex<T>::operator=(const myComplex<T> &r) {
    this->re = r.re;
    this->im = r.im;
    return *this;
}
template <typename T> inline myComplex<T> &myComplex<T>::operator++() {
    this->re++;
    this->im++;
    return *this;
}
template <typename T> inline myComplex<T> myComplex<T>::operator++(int) {
    myComplex<T> cls = *this;
    this->re++;
    this->im++;
    return cls;
}

template <typename T>
myComplex<T> operator+(const myComplex<T> &obj1, const myComplex<T> &obj2) {
    return myComplex<T>(obj1.re + obj2.re, obj1.im + obj2.im);
}
template <typename T>
myComplex<T> operator+(const T a, const myComplex<T> &obj1) {
    return myComplex<T>(obj1.re + a, obj1.im);
}
template <typename T>
myComplex<T> operator+(const myComplex<T> &obj1, const T a) {
    return myComplex<T>(obj1.re + a, obj1.im);
}
template <typename T> myComplex<T> operator-(const myComplex<T> &r) {
    return myComplex<T>(-r.re, -r.im);
}
template <typename T>
bool operator==(const myComplex<T> &obj1, const myComplex<T> &obj2) {
    return obj1.re == obj2.re && obj1.im == obj2.im;
}
template <typename T>
bool operator!=(const myComplex<T> &obj1, const myComplex<T> &obj2) {
    return obj1.re != obj2.re || obj1.im != obj2.im;
}
template <typename T>
ostream &operator<<(ostream &output, const myComplex<T> &r) {
    output << r.re << " " << r.im;
    return output;
}
template <typename T> myComplex<T> conj(const myComplex<T> &r) {
    return myComplex<T>(r.re, -r.im);
}