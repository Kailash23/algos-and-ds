/*
   Given an array of integers of size n which contains numbers from 0 to n - 2.
   Each number is present at least once. That is, if n = 5, numbers from 0 to 3
   is present in the given array at least once and one number is present twice.
   You need to find and return that duplicate number present in the array.
 */
#include <iostream>
using namespace std;

int findDuplicate(int numbers[], int size) {
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += numbers[i];
    }
    int expectedSum = ((size - 1) * (size - 2)) / 2;
    return actualSum - expectedSum;
}

int main() {
    int numbers[] = {0, 7, 2, 5, 4, 7, 1, 3, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "The duplicate number is: " << findDuplicate(numbers, size) << endl;
}

/*
  Output: The duplicate number is: 7
 */

// Note
/*
   1 + 2 + ... + n = n(n + 1) / 2, for n a natural number.
*/
