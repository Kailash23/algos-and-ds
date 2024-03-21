/*
   Given a two dimensional n*m array, print the array in a sine wave order. i.e.
   print the first column top to bottom, next column bottom to top and so on.
 */

#include <iostream>
using namespace std;

// void printSineWave(const vector<vector<int>> &matrix, int totalRows, int totalColumns) {
void printSineWave(int matrix[][500], int totalRows, int totalColumns) {
    for (int currentColumn = 0; currentColumn < totalColumns; currentColumn++) {
        if (currentColumn % 2 == 0) {
            // If currentColumn is even, print from top to bottom
            for (int currentRow = 0; currentRow < totalRows; currentRow++) {
                cout << matrix[currentRow][currentColumn] << " ";
            }
        } else {
            // If currentColumn is odd, print from bottom to top
            for (int currentRow = totalRows - 1; currentRow >= 0; currentRow--) {
                cout << matrix[currentRow][currentColumn] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int matrix[500][500];
    // vector<vector<int>> matrix(totalRows, vector<int>(totalColumns));

    int totalRows, totalColumns;

    // Ask the user for the number of rows
    cout << "Enter the number of rows: ";
    cin >> totalRows;

    // Ask the user for the number of columns
    cout << "Enter the number of columns: ";
    cin >> totalColumns;

    int nextValue = 1;
    // Initialize the matrix with increasing values
    for (int rowIndex = 0; rowIndex < totalRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < totalColumns; columnIndex++) {
            matrix[rowIndex][columnIndex] = nextValue++;
        }
    }

    printSineWave(matrix, totalRows, totalColumns);
}

/*
   3 4
   1 5 9 10 6 2 3 7 11 12 8 4
 */

/**
 * 00 01 02 03
 * 10 11 12 13
 * 20 21 22 23
 */

/**
 * Time Complexity : O (numRows * numColumns)
 * Space Complexity : O(1)
 */