/*
   Longest Subset
   Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int max(int arr[], int n){
	int ans = 0;
	unordered_map<int,int> map;
	int sum = 0;
	for(int i=0; i<n; i++) {
		if(arr[i]==0) {
			arr[i] = -1;
		}
	}
	for(int i=0; i<n; i++) {
		sum = sum + arr[i];
		if(map.find(sum) != map.end()) {
			if(ans < i-map[sum]) {
				ans = i-map[sum];
			}
		} else {
			map[sum] = i;
		}
	}
	return ans;
}

int main(){
	int arr[] = {1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<max(arr,n);
}
