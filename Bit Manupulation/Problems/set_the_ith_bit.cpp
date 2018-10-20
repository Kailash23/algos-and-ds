/*
   Code : Set ith bit

   You are given two integers N and i. You need to make ith bit of binary
   representation of N to 1 and return the updated N.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int turnOnIthBit(int n, int i){
	n = n | 1 << i;
	return n;
}

int main(){
	int n, i;
	cin >> n >> i;
	cout << turnOnIthBit(n, i);
}

/*
   4 1
   6
 */
