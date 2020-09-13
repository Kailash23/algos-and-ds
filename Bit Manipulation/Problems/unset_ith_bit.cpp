/*
   Code : Unset ith bit

   You are given two integers N and i. You need to make ith bit of binary
   representation of N to 0 and return the updated N.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int turnOffIthBit(int n, int i) {
    n = n & ~(1 << i);
    return n;
}

int main() {
    int n, i;
    cin >> n >> i;
    cout << turnOffIthBit(n, i);
}

/*
   7 2
   3
 */

/*
	7 - 8 4 2 1
		0 1 1 1			----A

		0 1 0 0	 (1 << i)
		1 0 1 1 ~(1 << i)		-----B

		A & B
		0 1 1 1
	 &	1 0 1 1
		-------
		0 0 1 1  (3)
*/

/*
   x & 0 = 0
   x & 1 = x

   x | 0 = x
   x | 1 = 1

   x ^ 0 = x
   x ^ 1 = ~x (used for flipping)
 */
