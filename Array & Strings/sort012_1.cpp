/*
   You are given an integer array containing only 0s, 1s and 2s. Write a solution
   to sort this array using one scan only. You need to change in the given array itself.
   So no need to return or print anything.
 */

#include <iostream>
using namespace std;

void PrintArray(int arr[], int n){
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}


void sort012(int arr[], int n)  {		// 2 scan
	int pivot = 1;
	int pIndex = 0;
	int i;
	int pIndex2 = 0;
	for( i = 0; i < n; i++) {
		if(arr[i] <= pivot) {
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	for( i = 0; i < pIndex; i++) {
		if(arr[i] < pivot) {
			swap(arr[i], arr[pIndex2]);
			pIndex2++;
		}
	}
	PrintArray(arr, n);
}


int main(){
	int arr[] = {0,1,2,0,1,2,0,1,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort012(arr, n);
}

/*
   0 0 0 1 1 1 2 2 2
 */
