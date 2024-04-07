/*
   Given a random integer array, push all the zeros that are present to end of the array.
   The respective order of other elements should remain same. Change in the input array
   itself. You don't need to return or print elements. Don't use extra array.
 */
#include "../../include/utils.hpp"
#include <iostream>
using namespace std;

void pushZerosToEnd(int array[], int size) {
    int nextNonZeroIndex = 0;
    for (int currentIndex = 0; currentIndex < size; currentIndex++) {
        if (array[currentIndex] != 0) {
            swap(array[nextNonZeroIndex], array[currentIndex]);
            nextNonZeroIndex++;
        }
    }
    util::printArray(array, size);
}

int main() {
    int array[] = {1, 2, 0, 0, 2, 0, 3, 4, 0};
    int size = sizeof(array) / sizeof(array[0]);
    pushZerosToEnd(array, size);
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