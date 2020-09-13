/*
   Longest Subset

    Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.

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
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) { //Replacing all zeros with -1
        if (arr[i] == 0) {
            arr[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
        if (map.count(sum) > 0) { //Or map.find(sum) != map.end()
            if (ans < i - map[sum]) {
                ans = i - map[sum];
            }
        } else {
            map[sum] = i; //Saving sum as key to hashmap having value array index
        }
    }
    return ans;
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max(arr, n);
}

/*
   6
 */

/*
	0  1  1  0  1  1  0  0  1
	-1 1  1 -1  1  1 -1  -1 1  (replacing 0 with -1)
	-1 0  1  0  1  2  1  0  1  (max distance between any value of equal sum val in a hashmap is our answer)
		  *	       			*
		  <--------6--------> distance between first 1 and the last 1 is 6(ans).
  */
