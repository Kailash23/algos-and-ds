/*
   Given an integer elements A with a size of n, identify and print all the leaders present in the elements.
   An element A[i] is considered a leader if every element that follows it (i.e., all elements to its
   right) are less than or equal to A[i]. Print all the leaders in the order they appear in the elements,
   separated by space.

        Sample Input 1 :
        6
        3 12 34 2 0 -1

        Sample Output 1 :
        34 2 0 -1


        Sample Input 2 :
        5
        13 17 5 4 6

        Sample Output 2 :
        17 6

 */

#include <iostream>
using namespace std;

void printArrayLeaders(int *elements, int size) {
    int maxRight = elements[size - 1];
    cout << maxRight << " ";

    for (int i = size - 2; i >= 0; i--) {
        if (elements[i] >= maxRight) {
            maxRight = elements[i];
            cout << maxRight << " ";
        }
    }
}

int main() {
    int elements[] = {3, 12, 34, 2, 34, -1};
    int size = sizeof(elements) / sizeof(elements[0]);
    printArrayLeaders(elements, size);
    cout << endl;
}

/**
 * 3, 12, 34, 2, 34, -1
 *
 * Output : -1 34 34
 */

/**
 * Time Complexity : O (n) - due to a single backward scan through the array.
 *
 * Space Complexity : O (1)
 */