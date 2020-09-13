/*
   Code : Number is even or odd

   You are given two integers N and i.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int checkEvenOdd(int n) {
    n = n & 1;
    return n;
}

int main() {
    int n;
    cin >> n;
    if (checkEvenOdd(n)) {
        cout << "odd" << endl;
    } else {
        cout << "even" << endl;
    }
}

/*
   7
   odd
 */
