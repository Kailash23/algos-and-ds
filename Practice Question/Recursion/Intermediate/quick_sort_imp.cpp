/*
   Quick Sort Code

   Sort an array A using Quick Sort.
   Change in the input array itself. So no need to return or print anything.
 */

#include <iostream>
using namespace std;

int partition(int input[], int si, int ei){
	int pivot = input[si];
	int countSmaller = 0;
	for(int i = si + 1; i <= ei; i++) {
		if(input[i] <= pivot) {
			countSmaller++;
		}
	}
	int pivotIndex = si + countSmaller;
	input[si] = input[pivotIndex];
	input[pivotIndex] = pivot;
	int i = si;
	int j = ei;
	while(i < pivotIndex && j > pivotIndex) {
		if(input[i] <= pivot) {
			i++;
		} else if(input[j] > pivot) {
			j--;
		} else {
			swap(input[i], input[j]);
			i++;
			j--;
		}
	}
	return pivotIndex;
}

void quickSortHelper(int input[], int si, int ei){
	if(ei <= si) {
		return;
	}
	int pi = partition(input, si, ei);
	quickSortHelper(input, si, pi - 1);
	quickSortHelper(input, pi + 1, ei);
}

void quickSort(int input[], int size) {
	int si = 0;
	int ei = size - 1;
	quickSortHelper(input, si, ei);
}

int main(){
	int arr[] = {2,1,3,5,4,9,7};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, n);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

/*
   1 2 3 4 5 7 9
 */
