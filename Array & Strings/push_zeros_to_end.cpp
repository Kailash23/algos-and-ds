/*
   Given a random integer array, push all the zeros that are present to end of the array. The respective order of other elements should remain same.
   Change in the input array itself. You don't need to return or print elements. Don't use extra array.
 */

#include <iostream>
using namespace std;

void PrintArray(int arr[], int n){
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
}

void PushZeroesEnd(int arr[], int n){
	int zeroCount=0;
	int index=0;
	for(int i=0; i<n; i++) {
		if(arr[i]!=0) {
			arr[index++]= arr[i];
		} else {
			zeroCount++;
		}
	}
	for(int i=0; i<zeroCount; i++) {
		arr[index++]=0;
	}
	PrintArray(arr,n);
}

int main(){
	int arr[] = {1,2,0,0,2,0,3,4,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	PushZeroesEnd(arr,n);
}
