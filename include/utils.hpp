#pragma once
#include <iostream>

namespace util {

template <typename T>

void printArray(const T *arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

void printSquareMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
}