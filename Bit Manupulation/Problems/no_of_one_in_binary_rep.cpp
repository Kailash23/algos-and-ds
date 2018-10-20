/*
   Code : No of one in binary representaion

   You are given two integers N and i.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int noOfOne(int n){
	int count = 0;
	while(n > 0) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	cout << noOfOne(n);
}

/*
   15
   4
 */
