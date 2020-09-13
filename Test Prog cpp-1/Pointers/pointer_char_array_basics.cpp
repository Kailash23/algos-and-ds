#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3};
    char b[] = "abc";
    cout << a << endl; //0x61ff08
    cout << b << endl; //abc

    char *c = &b[0];
    cout << c << endl; //abc

    char c1 = 'a';
    char *pc = &c1;
    cout << &c1 << endl; //aabc
    cout << c1 << endl;  //a
    cout << pc << endl;  //aabc

    char str[] = "abcde";
    char *pstr = "abcde"; //pointer to temporary memory (Bad practice) (Read only space) Error might occur

    pc++;
    pc++;
    cout << pc << endl; //bc
    pstr++;
    cout << pstr << endl; //bcde
}
