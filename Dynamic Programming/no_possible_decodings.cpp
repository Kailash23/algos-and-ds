/*
   Let 1 represent ‘A’, 2 represents ‘B’, etc.
   count the number of possible decodings of the given digit sequence in form of array.
 */

#include <iostream>
using namespace std;

/* Unoptimized Recursion*/

// int num_codes_non_dp(int *n, int size) {
//  if(size == 1) {
//      return 1;
//  }
//  if(size == 0) {
//      return 1;
//  }
//
//  int output = num_codes_non_dp(n, size-1);
//
//  if((n[size - 2] * 10 + n[size-1]) <= 26) {
//      output += num_codes_non_dp(n, size-2);
//  }
//  return output;
// }

/* Optimized Recursion */

int num_codes_dp(int *n, int size, int *arr) {
	if(size == 1) {     // Size is one, which means only one code is possible (a-i)
		return 1;
	}
	if(size == 0) {     // Size is zero, which means only one code is possible ie empty string
		return 1;
	}
	if(arr[size] > 0) {     // If work is done already with this size return precomputed value.
		return arr[size];
	}

	int output = num_codes_dp(n, size-1, arr);     // Array reduced from back

	// If we reach here this means we are sure that size is greater than or equal to 2.

	if((n[size - 2] * 10 + n[size-1]) <= 26) {      // arr[size-2] :- second last digit arr[size-1] :- last digit
		output += num_codes_dp(n, size-2, arr);        // Do this if the number formed from second last and last digit of array is greater than 26.
	}

	arr[size] = output;     //Whatever output we get we will store it for further need.
	return output;
}

/* Iterative Solution */

// Here arr[i] means what is the possible number of codes if we consider only first i digits.

int num_codes_itr(int *input, int size) {
	int* output = new int[size + 1];
	output[0] = 1;      // Zero length num - one code possible
	output[1] = 1;      // One length num - one code possible

	for(int i = 2; i <= size; i++) {
		output[i] = 0;
		output[i] = output[i-1];        //copy value at output[i-1] to output[i] (output[i-1] represents what is the answer for first i-1 digits)
		if((output[i-2] * 10 + output[i-1]) <= 26) {
			output[i] += output[i-2];       // We will do this only if last 2 digit combo is less than 26.
		}
	}
	int ans = output[size];     //output[size] contains answer (possible num of codes)
	delete [] output;       // delete output array
	return ans;
}

int main(){
	int n;
	cout<<"Enter no of digits: ";
	cin>>n;
	cout<<"Enter Number: ";
	int *arr = new int[n];

	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	int *temp = new int[n+1];
	*temp = {};     // All elements are initialized with 0.

	//cout<<num_codes_dp(arr, n, temp);
	cout<<num_codes_dp(arr, n, temp);
}

// Time Complexity of the above solution is O(n) and it requires O(n) auxiliary space.
