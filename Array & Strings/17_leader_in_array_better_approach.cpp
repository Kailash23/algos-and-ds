/*
   Given an integer array A of size n. Find and print all the leaders present in the input array.
   An array element A[i] is called Leader, if all the elements following it (i.e. present at its right)
   are less than or equal to A[i].Print all the leader elements separated by space and in the same
   order they are present in the input array.
 */

#include <iostream>
#include <climits>
using namespace std;

void Leaders(int* arr, int len){
	int j = 0;
	int save[len]; //   int *save = new int[len]; or we can declare this way
	int largest = INT_MIN;
	for(int i = len - 1; i >= 0; i--) {
		if(arr[i] >= largest) {
			save[j] = arr[i];
			j++;
			largest = arr[i];
		}
	}
	for(int i = j - 1; i >= 0; i--) {
		cout << save[i] << " ";
	}
}


int main(){
	int arr[] = {3, 12, 34, 2,34,-1};
	int n = sizeof(arr) / sizeof(arr[0]);
	Leaders(arr, n);
}

/*
   34 34 -1
 */
