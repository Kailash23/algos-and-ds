/*
   Sum of Array

   Given an array of length N, you need to find and return the sum of all elements
   of the array.
   Do this recursively.
 */

#include <iostream>
using namespace std;

int sum(int input[], int n){
	if(n == 0) {
		return 0;
	}
	return input[0] + sum(input + 1, n - 1);
}

int main(){
	int arr[] = {3,2,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << sum(arr, n);
}

/*
   14
 */

/*
	int sum(int input[], int n) {
		if(n == 0) {
			return 0;
		}
		int s = 0;
		s += input[0];
		return s + sum(input + 1, n - 1);
	}
*/
