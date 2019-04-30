#ifndef __03_STRING__
#define __03_STRING__

#include <cstring>
#include <iostream>
using namespace std;
class myString {
  public:
    // myString str();
    myString();
    // myString str("sssde");
    myString(const char *data);
    // myString str(10);
    myString(const int lens);
    // myString str1 = str;
    myString(const myString &str);
    //析构
    ~myString();

  public:
    // str1 = str2
    myString &operator=(const myString &str);
    // str1 = "aaa";
    myString &operator=(const char *data);
    //重载[]
    char &operator[](const int index);
    // str1==str2;
    friend bool operator==(const myString &str1, const myString &str2);
    friend bool operator==(const myString &str1, const char *data);
    friend bool operator==(const char *data, const myString &str1);
    // str1!=str2;
    friend bool operator!=(const myString &str1, const myString &str2);
    friend bool operator!=(const myString &str1, const char *data);
    friend bool operator!=(const char *data, const myString &str1);
    // str1 > str2;
    friend int operator>(const myString &str1, const myString &str2);
    friend int operator>(const myString &str1, const char *data);
    friend int operator>(const char *data, const myString &str1);
    // str1 < str2
    friend int operator<(const myString &str1, const myString &str2);
    friend int operator<(const myString &str1, const char *data);
    friend int operator<(const char *data, const myString &str1);
    // 重载<<
    friend ostream &operator<<(ostream &output, const myString &str1);

  private:
    char *mData;
    int len;
};

#endif