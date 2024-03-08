/*
   We have given a 2D array which is sorted row-wise and column-wise.
   You have to find an element in that matrix.
 */

#include <iostream>
using namespace std;

void searchInSortedMatrix(int (*matrix)[30], int rowsCount, int columnsCount, int target) {
    if (rowsCount == 0 || columnsCount == 0) {
        cout << "Matrix is empty." << endl;
        return;
    }

    int row = 0, column = columnsCount - 1; // Start from the top-right corner
    while (column < columnsCount) {
        if (matrix[row][column] == target) {
            cout << "Found at " << row << "," << column << endl;
            return;
        } else {
            if (target < matrix[row][column]) {
                column--;
            } else if (target > matrix[row][column]) {
                row++;
            }
        }
    }
    cout << "Element not found" << endl;
}

int main() {
    int rows, columns, targetElement;
    int matrix[30][30];
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    cout << "Enter the elements of the matrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Element to search: ";
    cin >> targetElement;

    searchInSortedMatrix(matrix, rows, columns, targetElement);
}

/*
   First Approach -
    Traverse each element one by one and find that number. - Time:O(m*n)

   Second Approach -
    Apply binary search at each row or column. Time: O(mLog(n)) - row
                                                        OR
                                                      O(nLog(n)) - column

   Third Approach -
    Go to top right corner (0, col-1). If x is greater than that number move down ie increment x,
    ie move down in another row. If x is left is less than that number move left in the same
    column.

    O(rows + columns).
 */

/*
   5 4

   5  7  8  20
   9  11 13 30
   10 20 29 40
   15 23 30 50
   18 25 33 60

   Element to search: 33

   Found at location: (4, 2)
 */

/**
 * Time Complexity : O(rows + columns)
 * The search process involves moving left or down based on the comparison, ensuring that each step eliminates either one row or one column from the search space.
 *
 * Space Complexity : O(1)
 */