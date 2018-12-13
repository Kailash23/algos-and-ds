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

int firstIndex(int input[], int size, int x, int passes = 0){
	if(size == 0) {
		return -1;
	}
	if(input[0] == x) {
		return passes;
	} else {
		return firstIndex(input + 1, size - 1, x, ++passes);	// Removing element form front
	}
}

int main(){
	int arr[] = {1, 6, 4, 5, 6, 4, 3, 4, 5, 6, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 5;
	int ans = firstIndex(arr, n, x);
	cout << ans;
}

/*
   3
 */

/*
	int firstIndex(int arr[], int size, int x){
		if(size == 0) {    // Array size is 0 ie element not present
			return -1;
		}
		if(arr[0] == x) {   // If element found at first index (0), then return 0
			return 0;
		}
		int pos = firstIndex(arr + 1, size - 1, x);
		if(pos == -1) {
			return -1;	// Since we reached to end of the array and we didn't found x.
		} else {
			return pos + 1;		// We found the element increment the pos for each call stack.
		}
	}
*/
