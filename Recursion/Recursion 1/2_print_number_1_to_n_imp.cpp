/*
   Print Numbers

   Given the code to print number from 1 to n in increasing order recursively.
 */

#include <iostream>
using namespace std;

void print(int n){
	if(n == 1) {
		cout << n << " ";
		return;
	}
	print(n - 1);
	cout << n << " ";
}

int main(){
	int n;
	cin >> n;
	print(n);
}

/*
   6
   1 2 3 4 5 6
 */
