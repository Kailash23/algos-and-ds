/*
   Print Spiral : Given an N*M 2D array, print it in spiral form. That is, first
   you need to print the 1st row, then last column, then last row and then first
   column and so on.
 */

#include <iostream>
using namespace std;

void spiralPrint(int input[][1000], int row, int col) {
    int top = 0, bottom = row - 1, left = 0, right = col - 1;
    int dir = 0;
    while (top <= bottom && left <= right) {
        if (dir == 0) {
            for (int i = left; i <= right; i++) {
                cout << input[top][i] << " ";
            }
            top++;
        }
        if (dir == 1) {
            for (int i = top; i <= bottom; i++) {
                cout << input[i][right] << " ";
            }
            right--;
        }
        if (dir == 2) {
            for (int i = right; i >= left; i--) {
                cout << input[bottom][i] << " ";
            }
            bottom--;
        }
        if (dir == 3) {
            for (int i = bottom; i >= top; i--) {
                cout << input[i][left] << " ";
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
}

int main() {
    int arr[100][100];
    int m, n;
    cin >> m >> n;
    int count = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = count++;
        }
    }
    spiralPrint(arr, m, n);
}
