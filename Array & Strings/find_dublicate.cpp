//Find Dublicate
#include<iostream>
using namespace std;

int FindNum(int arr[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	int nsum = ((n-1)*(n-2))/2;
	return sum-nsum;
}

int main(){
	int arr[] = {0,7,2,5,4,7,1,3,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<FindNum(arr,n);
}
