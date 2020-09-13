/*
   Program to rotate array left and right.
 */

#include <iostream>
using namespace std;

void rotate_right(int a[], int n) {
    if (n <= 1) {
        return;
    }
    swap(a[n - 1], a[n - 2]);
    rotate_right(a, n - 1);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int b[] = {5, 6, 7, 8, 9};
    int n = sizeof(b) / sizeof(b[0]);
    rotate_right(b, n);
    print_array(b, n);
}

/*
   9 5 6 7 8
 */
