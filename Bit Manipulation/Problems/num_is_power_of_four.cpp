/*
   Code : Check whether number is power of four or not.

   You are given two integers N and i.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

bool isPowerOf4(int n) {
    bool isPowerOfTwo = n && !(n & (n - 1));
    if (!isPowerOfTwo) {
        return false;
    }
    bool ans = !(n & 0xAAAAAAAA); //  Get all even bits of n
    return ans;
}

int main() {
    int n;
    cin >> n;
    if (isPowerOf4(n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

/*
   64
   Yes
 */

/*
   Time Complexity is O(1)
 */

/*
   The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and
   all odd bits as 0.
   A in binary is 1010
 */
