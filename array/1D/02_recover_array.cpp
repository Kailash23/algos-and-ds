/*
An array is given which is formed by extracting mid element one by one.
You have to recover original array from that array. if no of elements is odd
there is only one mid so we will consider this, but if array size is even we
will have two mid and we will consider first one. This is how given array is formed.
You just have recover original array.

    Output - 3 2 4 1 5
    Input - 1 2 3 4 5

    Output - 3 4 2 5 1 6
    Input - 1 2 3 4 5 6
*/

#include "../../include/utils.hpp"
#include <iostream>
using namespace std;

void recoverArray(int source[], int rearranged[], int length) {
    // Edge case: empty or invalid length
    if (length <= 0) {
        return;
    }

    int leftIndex, rightIndex;
    int middleIndex = length / 2;
    int i = 0;

    int isEvenLength = length % 2 == 0;

    if (isEvenLength) {
        leftIndex = middleIndex - 1;
        rightIndex = middleIndex;
    } else {
        rearranged[middleIndex] = source[i];
        leftIndex = middleIndex - 1;
        rightIndex = middleIndex + 1;
        i++;
    }

    while (i < length) {
        rearranged[leftIndex] = source[i];
        leftIndex--;
        i++;
        rearranged[rightIndex] = source[i];
        rightIndex++;
        i++;
    }
}

int main() {
    int source[] = {5, 1, 5, 8, 9, 2};
    int length = sizeof(source) / sizeof(source[0]);
    int rearranged[length];
    recoverArray(source, rearranged, length);
    util::printArray(rearranged, length);
}

/**
 * Odd Case :
 *
 * Input: 4 6 2 8 1 0 7
 * Output: 0 8 6 4 2 1 7
 *
 * Even Case :
 *
 * Input: 5 1 5 8 9 2
 * Output: 9 5 5 1 8 2
 */

//  4  6  2  8  1  0  7
// (0)(1)(2)(3)(4)(5)(6)

// center =  midIndex

// X X X (4) X X X (odd) - Offset 0 - Place element in center + offset (i = 0) (4)
// X X 6 (4) X X X (even) - Offset 1 - Place element in center - offset (i = 1) (6)
// X X 6 (4) 2 X X (odd) - Offset 1 - Place element in center + offset (i = 2) (2)
// X 8 6 (4) 2 X X (even) - Offset 2 - Place element in center - offset (i = 3) (8)
// X 8 6 (4) 2 1 X (odd) - Offset 2 - Place element in center + offset (i = 4) (1)
// 0 8 6 (4) 2 1 X (even) - Offset 3 - Place element in center - offset (i = 5) (0)
// 0 8 6 (4) 2 1 7 (odd) - Offset 3 - Place element in center + offset (i = 6) (7)

//  5  1  5  8  9  2
// (0)(1)(2)(3)(4)(5)

// center =  midIndex - 1

// X X 5 X X X  (even) - Offset 0 - Place element in center - offset (i = 0) (5)
// X X 5 1 X X  (odd) - Offset 1 - Place element in center + offset (i = 1) (1)
// X 5 5 1 X X  (even) - Offset 1 - Place element in center - offset (i = 2) (5)
// X 5 5 1 8 X  (odd) - Offset 2 - Place element in center + offset (i = 3) (8)
// 9 5 5 1 8 X  (even) - Offset 2 - Place element in center - offset (i = 4) (9)
// 9 5 5 1 8 2  (odd) - Offset 3 - Place element in center + offset (i = 5) (2)

// 0 -1, +1, -2, +2 -> Can be solved by maintaining 2 pointer

/**
 * Time Complexity :
 *
 * Space Complexity :
 */