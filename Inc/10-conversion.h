#ifndef __10_CONVERSION__
#define __10_CONVERSION__
#include <iostream>

class Fraction {
   public:
    Fraction(int num, int den = 1) : m_numberator(num), m_denominator(den) {}
    operator double() const {
        return (double)(m_numberator) / (double)(m_denominator);
    }

   private:
    int m_numberator;
    int m_denominator;
};

#endif