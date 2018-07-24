/*
   Nearest Repetition
   Given an integer array, find and return the minimum distance between indexes of an element and its repetition.
 */
#include <iostream>
#include <unordered_map>
using namespace std;

int minDistance(int arr[], int n){
	unordered_map<int,int> map;
	int near = n;
	for(int i=0; i<n; i++) {
		if(map.find(arr[i])!=map.end()) {
			if(near > i - map[arr[i]]) {
				near = i - map[arr[i]];
			}
			map[arr[i]] = i;
		} else {
			map[arr[i]] = i;
		}
	}
	return near;
}

int main(){
	int arr[] = {2,3,1,4,5,6,7,3,1,8,9,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<minDistance(arr,n);
}
