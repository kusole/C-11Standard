#include "../Inc/03-string.h"

myString::myString() {
    len = 0;
    mData = new char[1];
    strcpy(mData, "");
}

myString::myString(const char *data) {
    if (data) {
        len = strlen(data);
        mData = new char[len + 1];
        strcpy(mData, data);
    } else {
        len = 0;
        mData = new char[1];
        strcpy(mData, "");
    }
}

myString::myString(const int lens) {
    len = lens;
    mData = new char[len + 1];
    strcpy(mData, "");
}

myString::myString(const myString &str) {
    len = str.len;
    mData = new char[len + 1];
    strcpy(mData, str.mData);
}

myString::~myString() {
    if (mData != NULL) {
        len = 0;
        delete[] mData;
        mData = NULL;
    }
}

myString &myString::operator=(const myString &str) {
    if (this == &str) {
        return *this;
    }
    if (mData != NULL) {
        len = 0;
        delete[] mData;
        mData = NULL;
    }
    len = str.len;
    mData = new char[len + 1];
    strcpy(mData, str.mData);
    return *this;
}

myString &myString::operator=(const char *data) {
    if (this->mData == data) {
        return *this;
    }
    if (mData != NULL) {
        len = 0;
        delete[] mData;
        mData = NULL;
    }
    if (data == NULL) {
        len = 0;
        mData = new char[1];
        strcpy(mData, "");
    } else {
        len = strlen(data);
        mData = new char[len + 1];
        strcpy(mData, data);
    }
    return *this;
}
char &myString::operator[](const int index) {
    static char sNull = '\0'; //不能返回局部变量的引用，这里用静态变量替换
    if (len >= index + 1 && index >= 0)
        return mData[index];
    else {
        cout << "Array out of index!" << endl;
        return sNull;
    }
}
bool operator==(const myString &str1, const myString &str2) {
    if (str1.len != str2.len) {
        return false;
    } else {
        if (!strcmp(str1.mData, str2.mData))
            return true;
        else
            return false;
    }
}

bool operator==(const myString &str1, const char *data) {
    if (str1.len != strlen(data)) {
        return false;
    } else {
        if (!strcmp(str1.mData, data))
            return true;
        else
            return false;
    }
}

bool operator==(const char *data, const myString &str1) {
    if (str1.len != strlen(data)) {
        return false;
    } else {
        if (!strcmp(str1.mData, data))
            return true;
        else
            return false;
    }
}

bool operator!=(const myString &str1, const myString &str2) {
    if (str1.len != str2.len) {
        return true;
    } else {
        if (!strcmp(str1.mData, str2.mData))
            return false;
        else
            return true;
    }
}

bool operator!=(const myString &str1, const char *data) {
    if (str1.len != strlen(data)) {
        return true;
    } else {
        if (!strcmp(str1.mData, data))
            return false;
        else
            return true;
    }
}

bool operator!=(const char *data, const myString &str1) {
    if (str1.len != strlen(data)) {
        return true;
    } else {
        if (!strcmp(str1.mData, data))
            return false;
        else
            return true;
    }
}

int operator>(const myString &str1, const myString &str2) {
    return strcmp(str1.mData, str2.mData);
}
int operator>(const myString &str1, const char *data) {
    return strcmp(str1.mData, data);
}
int operator>(const char *data, const myString &str1) {
    return strcmp(data, str1.mData);
}
int operator<(const myString &str1, const myString &str2) {
    return strcmp(str2.mData, str1.mData);
}
int operator<(const myString &str1, const char *data) {
    return strcmp(data, str1.mData);
}
int operator<(const char *data, const myString &str1) {
    return strcmp(str1.mData, data);
}

ostream &operator<<(ostream &output, const myString &str1) {
    output << str1.mData << '\t' << str1.len;
    return output;
}
