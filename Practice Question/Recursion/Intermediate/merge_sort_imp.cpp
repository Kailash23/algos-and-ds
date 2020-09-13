/*
   Merge Sort Code

   Sort an array A using Merge Sort.
   Change in the input array itself. So no need to return or print anything.
 */

#include <iostream>
using namespace std;

void merge(int arr[], int si, int ei) {
    int *output = new int[ei - si + 1];
    int mid = (si + ei) / 2;
    int i = si;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            output[k++] = arr[i++];
        } else {
            output[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        output[k++] = arr[i++];
    }
    while (j <= ei) {
        output[k++] = arr[j++];
    }
    int index = 0;
    for (int l = si; l <= ei; l++) {
        arr[l] = output[index++];
    }
    delete[] output;
}

void mergeSortHelper(int input[], int si, int ei) {
    if (ei <= si) {
        return;
    }
    int mid = (si + ei) / 2;
    mergeSortHelper(input, si, mid);
    mergeSortHelper(input, mid + 1, ei);
    merge(input, si, ei);
}

void mergeSort(int input[], int size) {
    int si = 0;
    int ei = size - 1;
    mergeSortHelper(input, si, ei);
}

int main() {
    int arr[] = {2, 4, 3, 1, 6, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

/*
   1 2 3 4 5 6 7
 */
