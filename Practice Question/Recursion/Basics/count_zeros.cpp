/*
   Count Zeros

   Given an integer n, count and return the number of zeros that are present in
   the given integer using recursion.
 */

#include <iostream>
using namespace std;

int countZeros(int n) {
	if(n < 9) {
		if(n == 0) {
			return 1;
		} else {
			return 0;
		}
	}
	int res;
	if(n % 10 == 0) {
		res = 1;
	} else {
		res = 0;
	}
	return res + countZeros(n / 10);
}

int main(){
	int n = 100020;
	cout << countZeros(n);
}

/*
   4
 */

/*
    int countZeros(int n) {
        if (n == 0)
            return 0;
        return (n % 10 == 0) ? 1 + countZeros(n / 10) : countZeros(n / 10);
    }
 */
