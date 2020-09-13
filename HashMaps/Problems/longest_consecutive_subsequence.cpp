/*
   Longest Consecutive Subsequence :
   
   You are given with an array of integers that contain numbers in random order.
   Write a program to find the longest possible sub sequence of consecutive
   numbers using the numbers from given array. You need to return the output
   array which contains consecutive elements. Order of elements in the output is
   not important.
   Best solution takes O(n) time.
   If two arrays are of equal length return the array whose index of smallest
   element comes first.

    Input:
    13
    2 12 9 16 10 5 3 20 25 11 1 8 6
    Output:
    8 9 10 11 12

    Input:
    7
    15 13 23 21 19 11 16
    Output:
    15 16

 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> longestSubsequence(int *arr, int n) {
    vector<int> temp;
    vector<int> max;
    unordered_map<int, bool> map;

    for (int i = 0; i < n; i++) { //Adding elements to hash map
        map[arr[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        int k = arr[i]; // Taking element from array and cheking all consecutive value in hashmap by inc it.
        while (map.count(k)) {
            temp.push_back(k);
            k++;
        }
        if (temp.size() > max.size()) {
            max = temp;
        }
        temp.clear();
    }
    return max;
}

int main() {
    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res;
    res = longestSubsequence(arr, n);
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
}

/*
   8 9 10 11 12
 */

/*
Alternate solution

	#include <unordered_map>

	vector<int> longestSubsequence(int * arr, int n) {
		unordered_map<int, bool> hm;
		for (int i = 0; i < n; i++) {
			if (hm.count(arr[i]) == 0) {
				hm[arr[i]] = true;
			}
		}
		vector<int> output;
		int maxCount = 1;
		int startNum = arr[0];
		for (int i = 0; i < n; i++) {
			int count = 0;
			int tempNum = arr[i];
			while (hm.count(tempNum) == 1) {
				count++;
				tempNum++;
			}
			if (count > maxCount) {
				maxCount = count;
				startNum = arr[i];
			}
		}
		output.push_back(startNum);
		maxCount--;
		while (maxCount != 0) {
			startNum++;
			output.push_back(startNum);
			maxCount--;
		}
		return output;
	}

*/
