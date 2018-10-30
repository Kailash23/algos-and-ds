/*
   Longest Subset

    Given an array, find and return the length of longest subarray containing equal
	number of 0s and 1s.

    Input:
    6
    1 0 0 1 1 1
    Output:
    4

    Input:
    10
    1 1 1 0 0 0 1 1 0 0
    Output:
    10

 */


#include <iostream>
#include <unordered_map>
using namespace std;

int max(int arr[], int n) {
	unordered_map<int,int> map;
	unordered_map<int,int> start;
	unordered_map<int,int> end;
	int sum = 0;
	int maxlen = -1;
	for(int i = 0; i < n; i++) {
		if(arr[i] == 0) {
			sum--;
			if(map.count(sum) > 0) {
				map[sum]++;
				end[sum] = i;
			} else {
				map[sum]++;
				start[sum] = i;
			}
		} else {
			sum++;
			if(map.count(sum) > 0) {
				map[sum]++;
				end[sum] = i;
			} else {
				map[sum]++;
				start[sum] = i;
			}
		}
	}
	unordered_map<int,int>:: iterator it = map.begin();
	while(it != map.end()) {
		int s = it->first;
		map[s] = end[s] - start[s];
		it++;
	}
	it =  map.begin();
	while(it!=map.end()) {
		maxlen = max(maxlen,it->second);
		it++;
	}
	return maxlen;
}

int main(){
	int arr[] = {1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<max(arr,n);
}

/*
   8
 */
