/*
   Minimum Count

   Given an integer N, find and return the count of minimum numbers, sum of whose
   squares is equal to N.
   That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and
   {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
   Note : x^y represents x raise to the power y.
 */

#include <iostream>
using namespace std;

int minCount(int n) {
    if (n == 1) {
        return 1;
    }
    if (n <= 0) {
        return 0;
    }
    for (int i = n / 2; i >= 1; i--) {
        if (n >= (i * i)) {
            return 1 + minCount(n - (i * i));
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n != -1) {
        cout << minCount(n) << endl;
        cin >> n;
    }
    cout << "exit!";
}

/*
   5
   2
 */
