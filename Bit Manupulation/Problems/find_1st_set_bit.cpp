/*
   Code : Find 1st set bit

   You are given an integer N. You need to return an integer M, in which only one
   bit is set which at position of lowest set bit of N (from right to left).
 */

#include <iostream>
using namespace std;

int returnFirstSetBit(int n){
	int count;
	int s = n & (n - 1);
	return n - s;
}

int main(){
	int n;
	cin >> n;
	cout << returnFirstSetBit(n);
}

/*
   12
   4
 */



/*
   Alternate Solution

   int returnFirstSetBit(int n) {
    n = n & (-1 * n);
    return n;
   }
 */
