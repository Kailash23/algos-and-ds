/*
   Program to rotate array left and right.
 */

#include <iostream>
using namespace std;

void rotate_left(int a[], int n) {
    if (n <= 1) {
        return;
    }
    swap(a[0], a[1]);
    rotate_left(a + 1, n - 1); // reducing from front
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    rotate_left(a, n);
    print_array(a, n);
}

/*
   2 3 4 5 1
 */
