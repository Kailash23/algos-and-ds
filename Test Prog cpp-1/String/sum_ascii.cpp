#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "dd";
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum = sum + (str[i] + 0);
    }
    cout << sum;
}

/*
   200
 */
