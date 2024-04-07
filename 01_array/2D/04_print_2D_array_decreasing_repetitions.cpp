/*
    Print 2D array

    Given a 2D integer array with n rows and m columns. Print the 0th row from input n times, 1st row n-1 times…..(n-1)th row will be printed 1 time.
    Input format :

    Line 1 : No of rows(n) & No of columns(m) (separated by space)

    Line 2 : Row 1 elements (separated by space)

    Line 3 : Row 2 elements (separated by space)

    Line 4 : and so on

    Sample Input :
    3 3
    1    2    3
    4    5    6
    7    8    9

    Sample Output :
    1    2    3
    1    2    3
    1    2    3
    4    5    6
    4    5    6
    7    8    9
 */

#include <iostream>
using namespace std;

void printRowsWithDecreasingRepetitions(int **input, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row - i; j++) {
            for (int k = 0; k < col; k++) {
                cout << input[i][k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m; // Reading number of rows and columns

    // Dynamically allocate memory for 2D array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    // Reading 2D array elements
    cout << "Enter array elements:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Printing 2D array as per the requirement
    printRowsWithDecreasingRepetitions(arr, n, m);

    // Deallocating memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i]; // Delete each sub-array
    }
    delete[] arr; // Delete the outer array

    return 0;
}

/**
 * Time Complexity :
 *
 * The outer loop runs n times, where n is the number of rows in the 2D array.
 * For each row i, the program prints n - i times, where i ranges from 0 to n-1.
 * n+(n−1)+(n−2)+...+1= n(n+1)/2
 *
 * Since each print operation involves iterating through all m columns, the time complexity is
 * O(m × n(n+1)/2) ie O(mn^2)
 *
 * n -> rows, m -> column
 *
 * Space Complexity : O(nm)
 */