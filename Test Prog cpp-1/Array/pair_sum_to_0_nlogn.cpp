/*
   Pair sum to 0, if element is used in one pair can't be used in another one.
 */
#include <algorithm>
#include <iostream>
using namespace std;

int PairSum(int *input, int n) {
    sort(input, input + n);
    int left = 0;
    int right = n - 1;
    int x, y, sum;
    bool found = false;
    while (left <= right) {
        x = input[left];
        y = input[right];
        sum = x + y;
        if (sum == 0) {
            found = true;
            left++;
            right--;
        }
        if (sum > 0) {
            right--;
        }
        if (sum < 0) {
            left++;
        }
        if (found) {
            if (x < 0)
                cout << x << " " << y << endl;
            else
                cout << -x << " " << -y << endl;
            found = false;
        }
    }
}

int main() {
    int arr[] = {4, -2, 4, -3, 6, -3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    PairSum(arr, n);
}
