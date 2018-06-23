/*
You are given with an array of integers that contain numbers in random order. Write a program to find and return the number which occurs maximum times in the given input.
If more than one element occurs same number of times in the input, return the element which is present in the input first.
Best solution takes O(n) time.
*/

#include<climits>
#include<iostream>
#include<unordered_map>
using namespace std;

int highestFrequency(int *input, int n){
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++){
		freq[input[i]]++;
	}
	int max=INT_MIN;
	int num;
	for(int j=0;j<n;j++){
		if(freq[input[j]]>max){
			max = freq[input[j]];
			num = input[j];
		}
	}
	return num;
}

int main(){
	int a[] = {1,2,3,4,5,6,3,2,4,3,5,3,5,5,5,5};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<highestFrequency(a,n);
}
