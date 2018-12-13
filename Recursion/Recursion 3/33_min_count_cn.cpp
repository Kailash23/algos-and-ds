/*
   Minimum Count

   Given an integer N, find and return the count of minimum numbers, sum of whose
   squares is equal to N.
   That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and
   {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
   Note : x^y represents x raise to the power y.
 */

#include <iostream>
#include <math.h>
using namespace std;

int minCount(int n){
	if(n <= 1) {
		return n;
	}
	int ans = n;
	for(int i = 1; i <= n; i++) {
		int square = i * i;
		if(square > n) {
			break;
		}
		ans = min(ans, minCount(n - square) + 1);
	}
	return ans;
}


int main(){
	int n;
	cin >> n;
	while(n != -1) {
		cout << minCount(n) << endl << endl;
		cin >> n;
	}
	cout << "exit!";
}

/*
   10
   2
 */

/*
   3^3 & 1^1
 */
