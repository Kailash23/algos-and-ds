/*
   Code: Selection Sort
 */

#include <iostream>
using namespace std;

int selectionSort(int input[], int n) {
    for (int i = 0; i < n - 1; i++) { // Till second last element (last one is sorted obviously)
        int min = input[i], minIndex = i;
        for (int j = i + 1; j < n; j++) { // For finding min element
            if (input[j] < min) {
                min = input[j];
                minIndex = j;
            }
        }
        // Swap
        int temp = input[i];
        input[i] = input[minIndex];
        input[minIndex] = temp;
    }
}

int main() {
    int input[] = {3, 1, 6, 9, 0, 4};
    int size = sizeof(input) / sizeof(input[0]);
    selectionSort(input, size);
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
}

/*
   0 1 3 4 6 9
 */

/*
    After 1 round of selection sort smallest element is in its correct location
    But in Bubble sort largest element came to its correct location after 1 round.
    In order to sort an array of n elements we need to have n - 1 rounds.
  */
