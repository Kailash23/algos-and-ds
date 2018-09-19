/*
   First Index of Number

   Given an array of length N and an integer x, you need to find and return the
   first index of integer x present in the array. Return -1 if it is not present
   in the array.
   First index means, the index of first occurrence of x in the input array.
   Do this recursively. Indexing in the array starts from 0.
 */

#include <iostream>
using namespace std;

int findPos(int arr[], int n, int x){
	if(n == 0) {    // Array size is 0 ie element not present
		return -1;
	}
	if(arr[0] == x) {   // If element found at first index (0), then return 0
		return 0;
	}
	int pos = findPos(arr + 1, n - 1, x);
	if(pos == -1) {
		return pos;
	} else {
		return pos + 1;
	}
}

int main(){
	int arr[] = {1,6,4,5,6,4,3,4,5,6,2,3,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 5;
	int ans = findPos(arr, n, x);
	cout << ans;
}

/*
   3
 */
