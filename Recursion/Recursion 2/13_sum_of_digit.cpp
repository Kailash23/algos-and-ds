/*
   Sum of digits (recursive)

   Write a recursive function that returns the sum of the digits of a given integer.
 */

#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n <= 9) {
        return n;
    }
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int i = 12345;
    cout << sumOfDigits(i);
}

/*
   15
 */
