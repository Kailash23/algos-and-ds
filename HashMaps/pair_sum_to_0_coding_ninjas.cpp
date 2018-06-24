/*
Code : Pair Sum to 0
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
A contains all non-zero values
*/

#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

void PairSum(int *input, int n){
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		m[input[i]]++;
	}

	for(int i=0;i<n;i++){
		int key = input[i];
		if(m.count(-key)!=0 && m[key]!=0){
			int times = m[key]*m[-key];
			while(times != 0){
				cout<<min(key,(-key));
				cout<<" "<<max(key,(-key))<<"\n";
				times--;
			}
			m[key]=0;
			m[-key]=0;
		}
	}
	for(int i=0;i<n;i++){
		cout<<m[input[i]]<<" ";
	}
}


int main(){
	int arr[]={1,2,-1,-2,3,5,4,-6,6,6,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	PairSum(arr,n);
}
