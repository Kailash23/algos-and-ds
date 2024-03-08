/*
   Given 2 sorted arrays (in increasing order), find a path through the intersections
   that produces maximum sum and return the maximum sum. That is, we can switch from
   one array to another array only at common elements. If no intersection element is
   present, we need to take sum of all elements from the array with greater sum.

    Sample Input :

    Array 1 : 1 5 10 15 20 25
    Array 2 : 2 4 5 9 15

    Sample Output :
    81

    We start from array 2 and take sum till 5 (sum = 11). Then we'll switch to array at element 10 and take till 15. So sum = 36. Now, no elements left in array after 15, so we'll continue in array 1. Hence sum is 81

 */

#include <iostream>
using namespace std;

long maxPathSum(int array1[], int array2[], int len1, int len2) {

    int sumArray1 = 0, sumArray2 = 0, totalMaxSum = 0;
    int index1 = 0, index2 = 0;

    while (index1 < len1 && index2 < len2) {
        if (array1[index1] < array2[index2]) {
            sumArray1 += array1[index1++];
        } else if (array1[index1] > array2[index2]) {
            sumArray2 += array2[index2++];
        } else {
            sumArray1 += array1[index1++];
            sumArray2 += array2[index2++];
            totalMaxSum += max(sumArray1, sumArray2);
            sumArray1 = sumArray2 = 0;
        };
    };

    while (index1 < len1) {
        sumArray1 += array1[index1];
        index1++;
    }

    while (index2 < len2) {
        sumArray2 += array2[index2];
        index2++;
    }
    totalMaxSum += max(sumArray1, sumArray2);
    return totalMaxSum;
}

int main() {
    int array1[] = {};
    int len1 = sizeof(array1) / sizeof(array1[0]);

    int array2[] = {};
    int len2 = sizeof(array2) / sizeof(array2[0]);

    cout << maxPathSum(array1, array2, len1, len2) << endl;
}

// Dry Run

// { 1, 5, 10, 15, 20, 25 } A1
// { 2, 4, 5, 9, 15 } A2

// sumArray1 1,6, 10, 25 (*15) , 20, 25
// sumArray2 2,6,11 (*5) 9, 24
// totalMaxSum - 11 + 25 + 45 = 81

/*

Explanation:

Treasure Trail Challenge

Imagine you have two roads in front of you, each filled with treasures. Both roads are special because they are sorted from least valuable treasures to the most valuable ones as you move forward. Sometimes, these roads cross, allowing you to jump from one road to the other at these crossing points. Your challenge is to collect as much treasure as possible!

Rules:

You can start collecting treasures from the beginning of either road.
You can only switch from one road to the other at places where they have the same amount of treasure (these are like magic portals that connect the two roads).
If there’s no place where the roads cross, just pick the road that has more treasure from start to end.
Your goal is to maximize the total value of the treasures you collect.
Your Task:
Given the amount of treasure on two roads, figure out the way to collect the maximum amount of treasure. Tell us the total value of the treasures you would collect following the best path.

Example Challenge:

Road 1 has treasures worth: 1, 5, 10, 15, 20, 25
Road 2 has treasures worth: 2, 4, 5, 9, 15
Solution to the Example:

Start on Road 2 and collect treasures until you find a common treasure amount with Road 1 (at treasure worth 5).
At the common treasure, check which road has more treasure until the next common treasure (or the end if there are no more common treasures). Choose that road and continue your collection.
In this case, you would switch to Road 1 at the common treasure worth 5, then collect treasures from Road 1.
Keep doing this until you have collected all the treasures from the best path.
What's the maximum treasure you can collect? For the example above, you would collect treasures worth a total of 81.

*/

/**
 * Time Complexity: O(len1 + len2) :  The solution iterates through each element of both arrays at most once.
 *
 * Space Complexity: O(1)
 */