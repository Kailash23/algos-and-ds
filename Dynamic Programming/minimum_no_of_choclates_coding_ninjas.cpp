/*
   Minimum Number of Chocolates

   Noor is a teacher. She wants to give some chocolates to the students in her class.
   All the students sit in a line and each of them has a score according to performance.
   Noor wants to give at least 1 chocolate to each student. She distributes chocolates
   to them such that If two students sit next to each other then the one with the higher
   score must get more chocolates. Noor wants to save money, so she wants to minimise the
   total number of chocolates.
   Note that when two students have equal score they are allowed to have different number of chocolates.
 */

#include <iostream>
using namespace std;

int getMin(int *arr, int n) {
    int *dp = new int[n + 1];
    dp[0] = 1;

    int i = 0;
    int sum = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
    }

    for (i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1] && dp[i] <= dp[i + 1]) {
            dp[i] = dp[i + 1] + 1;
        }
    }

    for (i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    delete[] dp;
    return sum;
}

int main() {
    int arr[] = {2, 5, 3, 6, 4, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    getMin(arr, n);
}
