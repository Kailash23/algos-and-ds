/*
	An array is given which is fromed by extracting mid element one by one.
	You have to recover original array from that array. if no of elements is odd
	there is only one mid so we will consider this, but if array size is even we
	will have two mid and we will consider frist one. This is how given array is fromed.
	You just have recover original array.

	Output - 3 2 4 1 5
	Input - 1 2 3 4 5

	Output - 3 4 2 5 1 6
	Input - 1 2 3 4 5 6
*/

#include <iostream>
using namespace std;

void RecoverArray(int input[], int output[], int n){
	int left, right;
	int mid = n / 2;
	int i = 0;
	if(n % 2 != 0) {
		left = mid - 1;
		right = mid + 1;
		i++;
	} else {
		left = mid - 1;
		right = mid;
	}

	while(i < n) {
		output[left] = input[i];
		left--;
		i++;
		output[right] = input[i];
		right++;
		i++;
	}
}

void PrintArray(int arr[], int n){
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main(){
	int input[] = {3,2,4,1,5};
	// Output: 1 2 3 4 5
	int n = sizeof(input) / sizeof(input[0]);
	int output[n];
	RecoverArray(input, output, n);
	PrintArray(output, n);
}
