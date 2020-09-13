/*
   Sum of digits (recursive)

   Write a recursive function that returns the sum of the digits of a given integer.
 */

#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int n = 1234;
    cout << sumOfDigits(n);
}

/*
	int sumOfDigits(int n) {
		return (n == 0) ? 0 : (n % 10) + sumOfDigits(n / 10);
	}
 */
