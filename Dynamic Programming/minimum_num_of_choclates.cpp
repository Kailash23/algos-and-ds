/*
   Minimum Number of Chocolates

   Noor is a teacher. She wants to give some chocolates to the students in her class.
   All the students sit in a line and each of them has a score according to performance.
   Noor wants to give at least 1 chocolate to each student. She distributes chocolate
   to them such that If two students sit next to each other then the one with the
   higher score must get more chocolates. Noor wants to save money, so she wants to
   minimise the total number of chocolates.
   Note that when two students have equal score they are allowed to have different number of chocolates.
 */

#include <iostream>
using namespace std;

int getMin(int *arr, int n) {
    int *choclates = new int[n];

    if (arr[0] < arr[1]) {
        choclates[0] = 1;
        choclates[1] = 2;
    } else if (arr[0] > arr[1]) {
        choclates[0] = 2;
        choclates[1] = 1;
    } else {
        choclates[0] = 1;
        choclates[1] = 1;
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            choclates[i] = 1;
        } else if (arr[i] > arr[i - 1]) {
            int s = choclates[i - 1];
            s++;
            choclates[i] = s;
        } else {
            int count = 0;
            int j = i;
            while (arr[j + 1] < arr[j]) {
                count++;
                j++;
            }
            if (count == 0) {
                choclates[i] = 1;
            } else {
                int s = count;
                while (s >= 0) {
                    choclates[i++] = s + 1;
                    s--;
                }
                i--;
            }
        }
    }
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += choclates[j];
    }
    return sum;
}

int main() {
    int arr[] = {3, 3, 3, 3, 3, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << getMin(arr, n);
}
