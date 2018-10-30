/*
   Zero Sum Sub-Array
   You are given with an array (of size N) consisting of positive and negative integers that contain numbers in random order.
   Write a program to return true if there exists a sub-array whose sum is zero else, return false.
 */
#include <iostream>
#include <unordered_map>
using namespace std;

bool subArrayZeroSum(int input[], int n){
	unordered_map<int,bool> m;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += input[i];
		if(sum == 0 || m.count(sum) != 0) {
			return true;
		}
		m[sum] = true;
	}
	return false;
}

int main(){
	int arr[] = {7,1,3,-4,5,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	if(subArrayZeroSum(arr, n)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

/*
   true
 */
