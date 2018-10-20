/*
   Code : Clear all bits from MSB

   You are given two integers N and i. You need to clear all bits from MSB to ith
   bit (start i from right to left) and return the updated N.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int clearAllBits(int n, int i){
	int mask = (1 << i) - 1;
	return n & mask;
}

int main(){
	int n, i;
	cin >> n >> i;
	cout << clearAllBits(n, i);
}

/*
   12 2
   0
 */

/*
   12 2

   8 4 2 1
   1 1 0 0	(12) --- A

   0 1 0 0	(1 << 2) --- B
   0 0 1 1	(A - 1)

	   1 1 0 0	--- A
	 &  0 0 1 1	--- B
	   -------
	   0 0 0 0
 */
