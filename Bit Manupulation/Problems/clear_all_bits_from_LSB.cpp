/*
   Code : Clear all bits from LSB

   You are given two integers N and i. You need to clear all bits from LSB to ith
   bit (start i from right to left) and return the updated N.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int clearAllBits(int n, int i){
	int m = ~((1 << (i + 1)) - 1);
	return m & n;
}

int main(){
	int n, i;
	cin >> n >> i;
	cout << clearAllBits(n, i);
}
