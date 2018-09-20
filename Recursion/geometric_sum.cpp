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
	if(k == 0) {
		return 1;
	}
	double sum = 1 / (pow(2, k));
	return sum + geometricSum(k - 1);
}

int main(){
	int k = 5;
	cout << geometricSum(5);
}

/*
   1.96875
 */
