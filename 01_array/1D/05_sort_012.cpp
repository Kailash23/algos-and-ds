/*
   You are given an integer array containing only 0s, 1s and 2s. Write a solution
   to sort this array using one scan only. You need to change in the given array itself.
   So no need to return or print anything.
 */

#include "../../include/utils.hpp"
#include <iostream>
using namespace std;

void sortZeroesOnesTwos(int array[], int length) {
    int zeroIndex = 0;
    int twoIndex = length - 1;
    int currentIndex = 0;

    while (currentIndex <= twoIndex) {
        if (array[currentIndex] == 0) {
            swap(array[currentIndex], array[zeroIndex]);
            zeroIndex++;
            currentIndex++;
        } else if (array[currentIndex] == 2) {
            swap(array[currentIndex], array[twoIndex]);
            twoIndex--;
            // No increment for currentIndex here because we need to check the element swapped from twoIndex
        } else {            // Case for 1
            currentIndex++; // Move to the next element if it's 1
        }
    }
    util::printArray(array, length);
}

int main() {
    int array[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    int length = sizeof(array) / sizeof(array[0]);
    sortZeroesOnesTwos(array, length);
}

/*
   0 0 0 1 1 1 2 2 2
 */
