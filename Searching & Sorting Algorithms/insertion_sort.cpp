/*
   Code: Insertion Sort
 */

#include <iostream>
using namespace std;

int insertionSort(int input[], int n) {
    int j;
    for (int i = 1; i < n; i++) {
        int current = input[i];
        for (j = i - 1; j >= 0; j--) {
            if (current < input[j]) {
                input[j + 1] = input[j];
            } else {
                break;
            }
        }
        input[j + 1] = current;
    }
}

int main() {
    int input[] = {3, 1, 6, 9, 0, 4};
    int size = sizeof(input) / sizeof(input[0]);
    insertionSort(input, size);
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
}

/*
   0 1 3 4 6 9
 */

/*
   Sorted and Unsorted Half is maintained.
   There is no swapping in Insertion Sort, only shifting is done.
 */
