/*
   Code : LIS
   Given an array with N elements, you need to find the length of the longest subsequence
   of a given sequence such that all elements of the subsequence are sorted in strictly
   increasing order.
 */

#include <iostream>
using namespace std;

/* Solution 1*/

int lis_1(int *input, int n) {
    int *storage = new int[n];             // Length equal to input array length.
    storage[0] = 1;                        //LIS ending at first index ie 0 will always be 1
    for (int i = 1; i < n; i++) {          // We have to fill remaining array from i = 1 to i = n
        storage[i] = 1;                    // we have LIS of min length of 1 atleast.
        for (int j = i - 1; j >= 0; j--) { // Checking reverse back in array for calc LIS at that index
            if (input[j] >= input[i]) {    // If previous LIS count at j index is greater that or EQUAL to LIS count at index i then countinue
                continue;
            }
            int possibleAns = storage[j] + 1; // We can add 1 to get LIS count
            if (possibleAns > storage[i]) {
                storage[i] = possibleAns; //If poss ans is greater than previous stored val ie 1 update val in store array
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
        if (best <= storage[i]) {
            best = storage[i]; // We are searching for max value in the storage array cuz that will be our and (max LIS count)
        }
    }
    delete[] storage;
    return best;
}

/* Solution 2*/

int lis_2(int arr[], int n) {
    int *storage = new int[n];
    storage[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        int max = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                int op = storage[j] + 1;
                if (op > max) {
                    max = op;
                }
            }
        }
        storage[i] = max;
        if (max > ans) {
            ans = max;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int ans = lis_1(input, n);
    //int ans = lis_2(input,n);
    cout << ans << endl;
    delete[] input;
}

/*
   time complexity is O(n^2)
 */
