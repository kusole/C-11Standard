#ifndef __04_ACCOUNT__
#define __04_ACCOUNT__

class Account {
  public:
    static double mRate;
    static void set_rate(const double &x) {
        mRate = x;
    }
};
//double Account::mRate;可以不给初值
double Account::mRate = 8.0;

#endif