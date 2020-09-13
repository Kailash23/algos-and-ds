#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void Leaders(int *arr, int len) {
    vector<int> vec;
    int max = INT_MIN;

    for (int i = len - 1; i >= 0; i--) {
        if (arr[i] >= max) {
            max = arr[i];
            vec.push_back(max);
        }
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i] << " ";
    }
}

int main() {
    int arr[] = {3, 12, 34, 2, 0, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    Leaders(arr, size);
}

/*
   34 2 0 -1
 */
