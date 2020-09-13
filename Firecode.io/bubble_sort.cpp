/*
   Write a function that takes in an array of ints and the size of the array and
   uses the Bubble Sort algorithm to sort the array in ascending order.
   The function should return the same, in-place sorted array.
 */

int *bubble_sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
