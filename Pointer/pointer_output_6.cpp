#include <iostream>
using namespace std;

int main() {
    char b[] = "xyz";
    char *c = &b[0];
    cout << c << endl;    //xyz
    cout << c[0] << endl; //x
}
