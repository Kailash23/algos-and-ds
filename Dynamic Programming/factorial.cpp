/*
   Program to find nth fibonacci number. Where n is the index of number.
   n=0 means first fibonacci number.
 */

#include <iostream>
using namespace std;

/* Recursive Method Time Complexity :- Exponential*/
// int fib(int n) {
//  if(n == 0 || n == 1) {
//      return 1;
//  }
//  return fib(n-1) + fib(n-2);
// }

/* Recursive Method (Optimized)  Time Complexity :- O(n) */
int fib(int n, int * arr) {
	if(n == 0 || n == 1) {
		return 1;
	}
	if(arr[n]>0) {
		return arr[n];	//If number is already pre calculated and present in array then use it.
	}

	int output = fib(n-1, arr) + fib(n-2, arr);
	arr[n] = output;	// Saving inpu to array before returning it.
	return output;
}

/* Iterative Method */
int fibi(int n) {
	int * arr = new int[n+1];
	arr[0] = 1;
	arr[1] = 1;
	for(int i = 2; i <= n; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	int output = arr[n];
	delete [] arr;
	return output;
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n+1];
	cout<<fib(n,arr)<<endl;
	//cout<<fibi(n)<<endl;
}
