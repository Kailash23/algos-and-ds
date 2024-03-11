/*
   Given a random integer array, push all the zeros that are present to end of the array.
   The respective order of other elements should remain same. Change in the input array
   itself. You don't need to return or print elements. Don't use extra array.
 */
#include "../../include/utils.hpp"
#include <iostream>
using namespace std;

void pushZerosToEnd(int array[], int length) {
    int nonZeroIndex = 0;
    int zeroCount = 0;

    for (int i = 0; i < length; i++) {
        if (array[i] != 0) {
            array[nonZeroIndex++] = array[i];
        } else {
            zeroCount++;
        }
    }

    for (int i = 0; i < zeroCount; i++) {
        array[nonZeroIndex++] = 0;
    }

    util::printArray(array, length);
}

int main() {
    int array[] = {1, 2, 0, 0, 2, 0, 3, 4, 0};
    int length = sizeof(array) / sizeof(array[0]);
    pushZerosToEnd(array, length);
}

/**
 * 1 2 2 3 4 0 0 0 0
 */

/**
 * Time Complexity :
 * Shifting non zero elements Loop: O(n) - n is the length of array.
 * Filling Zero Loop - O(n) < n is the zero count > - This loop runs zeroCount times, where zeroCount is the number of zeros found in the array during the first loop.
 *
 * O(n) is the time complexity since the loops are sequential and not nested.
 *
 * Space Complexity : O(1) - Operation performed in-place.
 */