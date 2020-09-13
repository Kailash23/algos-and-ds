/*
   Last Index of Number

   Given an array of length N and an integer x, you need to find and return the
   last index of integer x present in the array. Return -1 if it is not present
   in the array.
   Last index means - if x is present multiple times in the array, return the index
   at which x comes last in the array.
   You should start traversing your array from 0, not from (N - 1).
   Do this recursively. Indexing in the array starts from 0.
 */

#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
    if (size == 0) {
        return -1;
    }
    if (input[size - 1] == x) {
        return size - 1;
    }
    return lastIndex(input, size - 1, x); // Removing element from back
}

int main() {
    int arr[] = {1, 5, 4, 3, 5, 5, 5, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int ans = lastIndex(arr, n, x);
    cout << ans;
}

/*
   10
 */

/*
	int lastIndex(int input[], int size, int x) {
		if(size == 0) {
			return -1;
		}
		int pos = lastIndex(input + 1, size - 1, x);
		if(input[0] == x) {
			return pos + 1;
		}
		if(pos == -1) {
			return -1;
		} else {
			return pos + 1;
		}
	}
*/
