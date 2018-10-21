/*
   Code Binary Search

   Given a sorted integer array (in ascending order) and an element x.
   You need to search this element x in the given input array using
   binary search. Return the index of element in the input.

   Indexing starts from 0.
   Return -1 if x is not present in the input array.
 */

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int val){
	int start = 0;
	int end = n - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == val) {
			return mid;
		}
		else if (arr[mid] > val) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}


int main(){
	int arr[] = {1,3,7,9,11,12,45};
	int size = sizeof(arr) / sizeof(arr[0]);
	int val = 3;
	cout << BinarySearch(arr, size, val);
}

/*
   1
 */
