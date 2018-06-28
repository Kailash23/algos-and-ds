/*
Zero Sum Sub-Array
You are given with an array (of size N) consisting of positive and negative integers that contain numbers in random order.
Write a program to return true if there exists a sub-array whose sum is zero else, return false.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

bool subArrayZeroSum(int input[], int n) {
	int sum=0,i;
	int j=0;
	while(j<n){
		 i=j;
		 sum=0;
		while(i<n){
			sum+=input[i];
			if(sum == 0){
				return true;
			}
			i++;
		}
		j++;
	}
	return false;
}

int main(){
	int arr[] = {7,1,3,-4,5,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<subArrayZeroSum(arr, n);

}
