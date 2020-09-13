/*
   Count Zeros

   Given an integer n, count and return the number of zeros that are present in
   the given integer using recursion.

   Sample Input :
   10204
   Sample Output
   2
 */

#include <iostream>
using namespace std;

int countZeros(int n) {
    if (n <= 9) {
        if (n == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (n % 10 == 0) {                 // is last digit is 0
        return 1 + countZeros(n / 10); // we will add 1 for that ^
    } else {
        return countZeros(n / 10);
    }
}

int main() {
    int i = 110103;
    cout << countZeros(i);
}

/*
   2
 */

/*
	int countZeros(int n) {
		if(n <= 9) {
			if(n == 0) {
				return 1;
			} else {
				return 0;
			}
		}
		int count = 0;
		if(n % 10 == 0) {
			count = 1;
		}
		return count + countZeros(n / 10);
	}
*/
