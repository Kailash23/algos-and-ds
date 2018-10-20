/*
   Code : Turn off 1st set bit

   You are given an integer Ni. You need to make first set bit of binary representation
   of N to 0 and return the updated N.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int turnOffFirstSetBit(int n){
	int count;
	return n & (n - 1);
}

int main(){
	int n;
	cin >> n;
	cout << turnOffFirstSetBit(n);
}

/*
   12
   8
 */
