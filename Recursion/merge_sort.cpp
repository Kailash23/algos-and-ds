/*
Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything
*/

#include<iostream>
using namespace std;

void merge(int arr[], int start, int end){
	int size = end-start+1;		// Size of array
	int mid = (start + end)/2;
	int *out = new int[size];		// Dynamic array
	int i = start;
	int j = mid+1;
	int k = 0;
	while(i <= mid && j <= end){
		if(arr[i]<arr[j]){
			out[k] = arr[i];
			i++;
			k++;
		} else {
			out[k] = arr[j];
			j++;
			k++;
		}
	}
	while(i <= mid){
		out[k] = arr[i];
		k++;
		i++;
	}
	while(j <= end){
		out[k] = arr[j];
		k++;
		j++;
	}

	int m =0;
	for(int i=start;i<=end;i++){
		arr[i] = out[m];
		m++;
	}
	delete [] out;
}

void merge_sort(int arr[], int start, int end){
	if(start >= end){
		return;
	}
	int mid = (start + end)/2;
	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);
	merge(arr,start,end);
}

int main(){
	int a[] ={6,5,4,3,2,1};
	merge_sort(a,0,5);
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
