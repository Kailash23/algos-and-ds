/*
   Print Spiral : Given an N*M 2D array, print it in spiral form. That is, first
   you need to print the 1st row, then last column, then last row and then first
   column and so on.
 */

#include <iostream>
using namespace std;

void spiralPrint(int input[][100], int row, int col) {
    int T = 0, B = row - 1, L = 0, R = col - 1, dir = 0;
    while (T <= B && L <= R) {
        if (dir == 0) {
            for (int i = L; i <= R; i++) {
                cout << input[T][i] << " ";
            }
            T++;
        } else if (dir == 1) {
            for (int i = T; i <= B; i++) {
                cout << input[i][R] << " ";
            }
            R--;
        } else if (dir == 2) {
            for (int i = R; i >= L; i--) {
                cout << input[B][i] << " ";
            }
            B--;
        } else if (dir == 3) {
            for (int i = B; i >= T; i--) {
                cout << input[i][L] << " ";
            }
            L++;
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
