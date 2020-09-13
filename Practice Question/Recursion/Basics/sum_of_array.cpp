/*

*/

#include <iostream>
using namespace std;

int sum(int input[], int n) {
    if (n == 0) {
        return 0;
    }
    return input[0] + sum(input + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sum(arr, n);
}
