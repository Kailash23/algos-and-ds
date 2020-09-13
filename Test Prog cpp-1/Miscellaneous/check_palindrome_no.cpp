#include <iostream>
using namespace std;

int main() {
    int n, num, digit, rev = 0;
    cout << "Enter a positive number: ";
    cin >> num;
    n = num;
    do {
        digit = num % 10;
        cout << "dig: " << digit << endl;
        rev = (rev * 10) + digit;
        cout << "rev: " << rev << endl;
        num = num / 10;
        cout << "num: " << num << endl;
    } while (num != 0);

    cout << "Reverse: " << rev << endl;
    if (n == rev) {
        cout << " Palindrome number ";
    } else {
        cout << " Not Palindrome number ";
    }
}
