#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int *p = &a;
    char c = 'a';
    char *ch = &c;
    cout << sizeof(p) << endl;  //4
    cout << sizeof(ch) << endl; //4
}
