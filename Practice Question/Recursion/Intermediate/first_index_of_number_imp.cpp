/*
   First Index of Number

   Given an array of length N and an integer x, you need to find and return the first
   index of integer x present in the array. Return -1 if it is not present in the array.
   First index means, the index of first occurrence of x in the input array.
   Do this recursively. Indexing in the array starts from 0.
 */

#include <iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
    if (size == 0) {
        return -1;
    }
    if (input[0] == x) {
        return 0;
    }
    int smallAns = firstIndex(input + 1, size - 1, x);
    if (smallAns == -1) {
        return -1;
    } else {
        return 1 + smallAns;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    cout << firstIndex(arr, n, x);
}

/*
   3
 */

int firstIndex(int input[], int size, int x, int passes = 0) {
    if (size == 0) {
        return -1;
    }
    return (input[0] == x) ? passes : firstIndex(input + 1, size - 1, x, ++passes);
}
