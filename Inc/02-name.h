#ifndef __02_NAME__
#define __02_NAME__

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class Name {
  public:
    Name(const char *str) {
        len = strlen(str);
        p = (char *)malloc((len + 1) * sizeof(char));
        strcpy(p, str);
    }

    Name(const Name &str) {
        len = str.len;
        p = (char *)malloc((len + 1) * sizeof(char));
        strcpy(p, str.p);
    }

    Name &operator=(const Name &str) {
        if (p != NULL) {
            free(p);
            p = NULL;
            len = 0;
        }
        this->len = str.len;
        this->p = (char *)malloc((this->len + 1) * sizeof(char));
        strcpy(p, str.p);
        return *this;
    }

    ~Name() {
        if (p != NULL) {
            free(p);
            p = NULL;
            len = 0;
        }
    }

    void printName() {
        cout << "\tp = " << this->p << "\tlen = " << strlen(p) << endl;
    }

  private:
    char *p;
    int len;
};

#endif