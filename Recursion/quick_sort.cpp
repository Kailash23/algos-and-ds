/*
Quick Sort Code

Sort an array using Quick Sort.
Change in the input array itself. So no need to return or print anything.
*/
#include<iostream>
using namespace std;

void swap(int*a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int partition(int arr[] , int start, int end){
	int countSmaller = 0;
	int pivot = arr[start];

	for(int i=start+1;i<=end;i++){
		if(arr[i]<=pivot){
			countSmaller++;
		}
	}

	int pivotIndex = start + countSmaller;

	swap(&arr[start],&arr[pivotIndex]);

	int i = start;
	int j = end;

	while(i<pivotIndex && j>pivotIndex){
		if(arr[i]<=pivot){
			i++;
		} else if(arr[j]>pivot){
			j--;
		} else {
			swap(&arr[i],&arr[j]);
			i++;
			j--;
		}
	}
	return pivotIndex;
}

void sort_quickly(int arr[], int start, int end){
 	if(start<end){
		int p = partition(arr, start, end);
		sort_quickly(arr,start,p-1);
		sort_quickly(arr,p+1,end);
	}
}

//OR

/*
void sort_quickly(int arr[], int start, int end){
	if(start>=end){
		return;
	}
	int c = partition(arr, start, end);
	sort_quickly(arr,start,c-1);
	sort_quickly(arr,c+1,end);
}
*/

void quickSort(int input[], int size) {
	sort_quickly(input, 0, size-1);
}

int main(){
	int arr[] = {6,3,8,9,7,1,5,2,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,n);
	print_array(arr,n);
}
