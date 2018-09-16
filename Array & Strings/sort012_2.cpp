/*
   You are given an integer array containing only 0s, 1s and 2s. Write a solution
   to sort this array using one scan only. You need to change in the given array
   itself. So no need to return or print anything.
 */

#include <iostream>
using namespace std;

void PrintArray(int arr[], int n){
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void sort012(int arr[], int n){		//1 scan
	int nz = 0;		// Track 0 from beginning
	int nt = n - 1;		// Track 2 from the end
	for(int i = 0; i <= nt; i++) {		// Move till i <= nt
		if(arr[i] == 0) {
			swap(arr[i], arr[nz]);		// If 0 swap arr[i] with arr[nz]
			nz++;		// Inc nz
		} else if(arr[i] == 2) {
			swap(arr[i], arr[nt]);		// If 2 swap arr[i] with arr[nt]
			nt--;		// Dec nt and i
			i--;
		}
	}
	PrintArray(arr, n);
}

int main(){
	int arr[] = {2,1,0,2,0,1,2,0};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort012(arr, n);
}

/*
   0 0 0 1 1 2 2 2
 */
