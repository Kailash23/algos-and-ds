/*
   Merge Sort Code

   Sort an array A using Merge Sort.
   Change in the input array itself. So no need to return or print anything
 */

#include <iostream>
using namespace std;

void merge(int arr[], int si, int ei){
	int size = ei - si + 1;     // Size of array
	int mid = (si + ei) / 2;
	int *out = new int[size];       // Dynamic array
	int i = si;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= ei) {
		if(arr[i] < arr[j]) {
			out[k] = arr[i];
			i++;
			k++;
		} else {
			out[k] = arr[j];
			j++;
			k++;
		}
	}
	while(i <= mid) {
		out[k] = arr[i];
		k++;
		i++;
	}
	while(j <= ei) {
		out[k] = arr[j];
		k++;
		j++;
	}
	int m = 0;
	for(int i = si; i <= ei; i++) {
		arr[i] = out[m];
		m++;
	}
	delete [] out;
}

void merge_sort(int arr[], int si, int ei){
	if(si >= ei) {
		return;
	}
	int mid = (si + ei) / 2;
	merge_sort(arr, si, mid);
	merge_sort(arr, mid + 1, ei);
	merge(arr, si, ei);
}

void mergeSort(int arr[], int size){
	int si = 0;
	int ei = size - 1;
	merge_sort(arr, si, ei);
}

int main(){
	int a[] = {6,5,4,3,2,1};
	int size = sizeof(a) / sizeof(a[0]);
	mergeSort(a, size);
	for(int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
}

/*
   1 2 3 4 5 6
 */
