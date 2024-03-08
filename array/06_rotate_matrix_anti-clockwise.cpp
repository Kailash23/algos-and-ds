/*
   Given an N * N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "../include/utils.hpp"

void rotateAntiClockwise(int **matrix, int size) {
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < row; column++) {
            util::swap(matrix[row][column], matrix[column][row]);
        }
    }

    for (int row = 0; row < size / 2; row++) {
        for (int column = 0; column < size; column++) {
            util::swap(matrix[abs(size - row - 1)][column], matrix[row][column]);
        }
    }
}

int main() {
    int dimension;
    cout << "Enter the dimension of the square matrix: ";
    cin >> dimension;

    int sequentialNumber = 0;
    // Below 2 lines - dynamically allocating memory for a two-dimensional (2D) square matrix of integers

    // This line allocates memory for an array of pointers, each of which will point to an array of integers (a row of the matrix).
    int **matrix = (int **)malloc(dimension * sizeof(int *));

    for (int i = 0; i < dimension; i++) {
        matrix[i] = (int *)malloc(dimension * sizeof(int));
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = sequentialNumber++; // Use sequentialNumber to fill matrix elements
        }
    }

    util::printSquareMatrix(matrix, dimension);

    rotateAntiClockwise(matrix, dimension);

    util::printSquareMatrix(matrix, dimension);

    // Freeing the allocated memory
    for (int i = 0; i < dimension; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/*
   3
   2 5 8
   1 4 7
   0 3 6

 */

/*
        Dynamic allocation of 2D array

        int** arr = new int*[rows];
        for(int i = 0; i < rows; i++) {
                arr[i] = new int[n];
        }
        delete [] arr;		// Array deletion 2D
*/
