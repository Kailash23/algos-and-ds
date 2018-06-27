/*
Longest Consecutive Subsequence :
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sub sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two arrays are of equal length return the array whose index of smallest element comes first.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> longestSubsequence(int *arr, int n){
	vector<int> temp;
	vector<int> max;
	unordered_map<int,int> map;

	for(int i=0;i<n;i++){
		map[arr[i]]++;
	}

	for(int i=0;i<n;i++){
		int k = arr[i];
		while(map.count(k)){
			temp.push_back(k);
			k++;
		}
		if(temp.size()>max.size()){
			max.clear();
			max = temp;
		}
		temp.clear();
	}
	return max;
}

int main(){
	int arr[] = {2,12,9,16,10,5,3,20,25,11,1,8,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> res;
	res = longestSubsequence(arr,n);
	for(auto it = res.begin(); it!=res.end();it++){
		cout<<*it<<" ";
	}
}
