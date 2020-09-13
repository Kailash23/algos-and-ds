#include <cstring>
#include <iostream>
using namespace std;

int main() {
    string str = "falon9";
    char chr[20];
    strcpy(chr, str.c_str());
    cout << chr;
}
