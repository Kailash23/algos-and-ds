/*
   Given an array of integers of size n which contains numbers from 0 to n - 2.
   Each number is present at least once. That is, if n = 5, numbers from 0 to 3
   is present in the given array at least once and one number is present twice.
   You need to find and return that duplicate number present in the array.
 */
#include <iostream>
using namespace std;

int FindNum(int arr[], int n){
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += arr[i];
	}
	int nsum = ((n - 1) * (n - 2)) / 2;
	return sum - nsum;
}

int main(){
	int arr[] = {0,7,2,5,4,7,1,3,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << FindNum(arr, n);
}

/*
   7
 */

/*
   1 + 2 + ... + n = n(n + 1) / 2, for n a natural number.
*/
