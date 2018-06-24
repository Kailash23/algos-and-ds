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
using namespace std;

void PairSum(int *input, int n){
	unordered_map<int,int> map;
	int sum=0;

	for(int i=0;i<n;i++){
		map[input[i]]++;
	}

	for(int i=0;i<n;i++){
		if(map[input[i]]>0){
			int k = sum - input[i];
			if(map.count(k)>0){
				for(int s=0;s<map[k];s++){
					if(k<0)
					cout<<k<<" "<<-k<<endl;
					else
					cout<<-k<<" "<<k<<endl;
				}
				map[input[i]]--;
			}
		}
	}
 }


int main(){
	int arr[]={1,2,-1,-2,3,5,4,-6,6,6,-2};
	int n = sizeof(arr)/sizeof(arr[0]);
	PairSum(arr,n);
}
