/*
   Code : Check whether number is power of two or not.

   You are given two integers N and i.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int powerOfTwo(int n){
	if((n & (n - 1)) == 0 && n > 0) {
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int n;
	cin >> n;
	if(powerOfTwo(n)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

/*
   16
   Yes
 */

/*
   Time Complexity is O(1)
 */
