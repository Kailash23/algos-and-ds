#include <cstring>
#include <iostream>
using namespace std;

void splitword(string str) {
    string strWords[4]; //array of string (static array)
    short counter = 0;

    for (short i = 0; i < str.length(); i++) {
        strWords[counter] += str[i];
        if (str[i] == '_') {
            counter++;
        }
    }

    for (int k = 0; k <= 4; k++) {
        cout << strWords[k] << endl;
    }
}

int main() {
    string s = {"Helloo world good morniing"};
    splitword(s);
}
