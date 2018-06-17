#include<iostream>
using namespace std;

int swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void sort012(int arr[], int n)  {
	int pivot = 1;
	int pIndex = 0;
	int i;
	int pIndex2=0;

	for( i=0;i<n;i++){
		if(arr[i]<=pivot){
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}

	for( i=0;i<pIndex;i++){
		if(arr[i]<pivot){
			swap(arr[i],arr[pIndex2]);
			pIndex2++;
		}
	}


	for(int j=0;j<n;j++){
		cout<<arr[j]<<" ";
	}
}


int main(){
	int arr[] = {0,1,2,0,1,2,0,1,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort012(arr,n);
}
