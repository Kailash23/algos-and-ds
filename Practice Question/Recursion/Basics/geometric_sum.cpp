/*
   Geometric Sum

   Given k, find the geometric sum i.e.
   1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)
   using recursion. Return the answer.
 */

#include <iostream>
#include <math.h>
using namespace std;

double geometricSum(int k) {
    if (k == 0) {
        return 1;
    }
    return (1 / pow(2, k)) + geometricSum(k - 1);
}

int main() {
    int k;
    cin >> k;
    cout << geometricSum(k);
}

/*
   3
   1.875
 */
