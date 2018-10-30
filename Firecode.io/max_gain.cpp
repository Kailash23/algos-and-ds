/*
   Given an array of integers, write a method - max_gain - that returns the
   maximum gain. Maximum Gain is defined as the maximum difference between 2
   elements in a list such that the larger element appears after the smaller
   element. If no gain is possible, return 0.
 */

#include <climits>

int max_gain(int arr[], int sz){
	int maxGain = 0;
	int minSoFar = INT_MAX;
	for(int i = 0; i < sz; i++) {
		if(arr[i] < minSoFar) {
			minSoFar = arr[i];
		}
		if(maxGain < arr[i] - minSoFar) {
			maxGain = arr[i] - minSoFar;
		}
	}
	return maxGain;
}
