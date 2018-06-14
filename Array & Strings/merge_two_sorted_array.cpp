// Merge two sorted arrays
#include<iostream>
using namespace std;

void PrintArray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

void merge(int arr1[],int size1, int arr2[], int size2, int ans[]){
	int i=0, j=0, index=0;
	while(i<size1 && j<size2){

		if((arr1[i]<=arr2[j])){
			ans[index] = arr1[i];
			i++;
		} else {
			ans[index] = arr2[j];
			j++;
		}
		index++;
	}

	if(i<size1){
		for(int k=i;k<size1;k++){
			ans[index++] = arr1[k];
		}
	}
	if(j<size2){
		for(int k=j;k<size2;k++){
			ans[index++] = arr2[k];
		}
	}
	PrintArray(ans,size1+size2);
}

int main(){
	int arr1[] = {0,2,4,6,8,10,200};
	int arr2[] = {1,2,3,5,7,9,11,14,22,123};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	int ans[n1+n2];
	merge(arr1,n1,arr2,n2,ans);
}
