/*
   Code : Pairs with difference K

   You are given with an array of integers and an integer K. Write a program to
   find and print all pairs which have difference K.
   Best solution takes O(n) time. And take difference as absolute.

    Input  :
    4
    5 1 2 4
    3
    Output  :
    2 5
    1 4

    Input  :
    4
    4 4 4 4
    0
    Output  :
    4 4
    4 4
    4 4
    4 4
    4 4
    4 4
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int fact(int n) {
    return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}

void printPairs(int *input, int n, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[input[i]]++;
    }
    unordered_map<int, int>::iterator it1 = map.begin();
    unordered_map<int, int>::iterator it2 = map.begin();
    while (it1 != map.end()) {
        it2 = map.begin();
        while (it2 != map.end()) {
            if (it2->first != it1->first) {
                if ((it2->first - it1->first) == k) {
                    int count = it2->second * it1->second;
                    for (int i = 0; i < count; i++) {
                        cout << min(it2->first, it1->first) << " " << max(it2->first, it1->first) << endl;
                    }
                }
            } else {
                int count = it2->second;
                if (count > 1 && (it2->first - it1->first) == k) {
                    count = (fact(count) / fact(count - 2)) / 2;
                    for (int i = 0; i < count; i++) {
                        cout << it2->first << " " << it2->first << endl;
                    }
                }
            }
            it2++;
        }
        it1++;
    }
}

int main() {
    int arr[] = {5, 1, 2, 4};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printPairs(arr, n, k);
}

/*
   2 5
   1 4
 */
