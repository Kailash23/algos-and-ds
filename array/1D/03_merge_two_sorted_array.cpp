/*
   Given two sorted arrays of Size M and N respectively, merge them into a third
   array such that the third array is also sorted.
 */

#include "../../include/utils.hpp"
#include <iostream>
using namespace std;

int *merge(int sortedArray1[], int sizeArray1, int sortedArray2[], int sizeArray2) {
    if (sizeArray1 == 0 && sizeArray2 == 0) {
        cout << "Both arrays are empty. Nothing to merge.";
        return nullptr;
    }

    int *mergedArray = new int[sizeArray1 + sizeArray2];

    int indexArray1 = 0, indexArray2 = 0;
    int mergedIndex = 0;

    while (indexArray1 < sizeArray1 && indexArray2 < sizeArray2) {
        if ((sortedArray1[indexArray1] <= sortedArray2[indexArray2])) {
            mergedArray[mergedIndex] = sortedArray1[indexArray1++];
        } else {
            mergedArray[mergedIndex] = sortedArray2[indexArray2++];
        }
        mergedIndex++;
    }

    if (indexArray1 < sizeArray1) {
        for (int k = indexArray1; k < sizeArray1; k++) {
            mergedArray[mergedIndex++] = sortedArray1[k];
        }
    }

    if (indexArray2 < sizeArray2) {
        for (int k = indexArray2; k < sizeArray2; k++) {
            mergedArray[mergedIndex++] = sortedArray2[k];
        }
    }

    return mergedArray;
}

int main() {
    int sortedArray1[] = {0, 2, 4, 6, 8, 10, 200};
    int sortedArray2[] = {1, 2, 3, 5, 7, 9, 11, 14, 22, 123};

    int sizeArray1 = sizeof(sortedArray1) / sizeof(sortedArray1[0]);
    int sizeArray2 = sizeof(sortedArray2) / sizeof(sortedArray2[0]);

    int *mergedArray = merge(sortedArray1, sizeArray1, sortedArray2, sizeArray2);
    util::printArray(mergedArray, sizeArray1 + sizeArray2);
    delete[] mergedArray;
}

/*
   0 1 2 2 3 4 5 6 7 8 9 10 11 14 22 123 200
 */

/**
 * Time Complexity : O(m + n) -> m - size of array 1, n - size of array 2
 *
 * Space Complexity :O(m + n) -> m - size of array 1, n - size of array 2
 */