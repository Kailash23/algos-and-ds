/*
   Nearest Repetition

   Given an integer array, find and return the minimum distance between indexes
   of an element and its repetition.

    Input :
    6
    1 3 1 5 4 3
    Output :
    2

    Input :
    7
    5 47 82 4 4 6 2
    Output :
    1

 */

#include <iostream>
#include <unordered_map>
using namespace std;

int minDistance(int arr[], int n) {
    unordered_map<int, int> map;
    int near = n; // Initially setting near = n cause max possible distance is equal to size of array.
    for (int i = 0; i < n; i++) {
        if (map.count(arr[i])) {
            if (near > i - map[arr[i]]) {
                near = i - map[arr[i]];
            }
            map[arr[i]] = i; // updating new position of arr[i] in map after calc nearest dist.
        } else {
            map[arr[i]] = i;
        }
    }
    return near;
}

int main() {
    int arr[] = {2, 3, 1, 4, 5, 6, 7, 3, 1, 8, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minDistance(arr, n);
}

/*
   6
 */

/*
2  3  1  4  5  6  7  3  1  8  9  0
0  1  2  3  4  5  6  7  8  9  10 11
   *                 *					near = (7 - 1) = 6
   	  *                 *				near = (8 - 2) = 6	(near will not update)
	   									because (6 > 6) is false

										Therefore and = 6
*/
