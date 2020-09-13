/*
   Quick Sort Code

   Sort an array using Quick Sort.
   Change in the input array itself. So no need to return or print anything.
 */

#include <iostream>
using namespace std;

int partition(int a[], int si, int ei) {
    int countSmaller = 0;
    int pivot = a[si];
    for (int i = si + 1; i <= ei; i++) {
        if (a[i] <= pivot) {
            countSmaller++;
        }
    }
    int pivotIndex = si + countSmaller;
    a[si] = a[pivotIndex];
    a[pivotIndex] = pivot;
    int i = si;
    int j = ei;

    while (i < pivotIndex && j > pivotIndex) {
        if (a[i] <= pivot) {
            i++;
        } else if (a[j] > pivot) {
            j--;
        } else {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void sort_quickly(int a[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int p = partition(a, si, ei);
    sort_quickly(a, si, p - 1);
    sort_quickly(a, p + 1, ei);
}

/*	OR
    void sort_quickly(int a[], int si, int ei){
        if(si < ei) {
            int p = partition(a, si, ei);
            sort_quickly(a, si, p - 1);
            sort_quickly(a, p + 1, ei);
        }
    }
 */

void quickSort(int input[], int size) {
    sort_quickly(input, 0, size - 1);
}

int main() {
    int a[] = {6, 3, 8, 9, 7, 1, 5, 2, 6};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

/*
   1 2 3 5 6 6 7 8 9
 */
