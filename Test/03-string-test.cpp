#include "../Src/03-string.cpp"

int main() {
    myString s0;
    myString s1("aa");
    myString s3("ab");
    myString s4 = s1;
    s0 = s1;
    cout << (s1 > s3) << endl;
    cout << (s3 > "acd") << endl;
    cout << (s4 != s1) << endl;
    cout << (s0 == s1) << endl;
    cout << s3[1] << endl;
    s0 = "abcdefg";
    cout << s0 << endl;
    myString *p = new myString[3];
    p[0] = "111";
    p[1] = "222";
    p[2] = "333";
    cout << p[0] << endl;
    cout << p[1] << endl;
    cout << p[2] << endl;
    delete []p;
    //myString S[3] = {"111", "222", "333"};
    return 0;
}