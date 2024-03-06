/*
   Given a two dimensional n*m array, print the array in a sine wave order. i.e.
   print the first column top to bottom, next column bottom to top and so on.
 */

#include <iostream>
using namespace std;

void wavePrint(int input[][500], int row, int col) {
    for (int i = 0; i < col; i++) {

        if (i % 2 == 0) {
            for (int j = 0; j < row; j++) {
                cout << input[j][i] << " ";
            }
        } else {
            for (int j = row - 1; j >= 0; j--) {
                cout << input[j][i] << " ";
            }
        }
    }
}

int main() {
    int arr[500][500];
    int m, n;
    cin >> m >> n;
    int count = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = count++;
        }
    }
    wavePrint(arr, m, n);
}

/*
   3 4
   1 5 9 10 6 2 3 7 11 12 8 4
 */
