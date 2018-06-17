/*
You are given an integer array containing only 0s, 1s and 2s. Write a solution to sort this array using one scan only.
You need to change in the given array itself. So no need to return or print anything.
*/

#include<iostream>
using namespace std;

int swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void sort012(int arr[], int n){
	int nz=0;
	int nt= n-1;
	int i=0;

	for(i=0;i<=nt;i++){
		if(arr[i] == 0){
			swap(arr[i],arr[nz]);
			nz++;
		} else if(arr[i] == 2) {
			swap(arr[i],arr[nt]);
			nt--;
			i--;
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]= {2,1,0,2,0,1,2,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort012(arr,n);
}
