/*
   Number of Digits

   Given the code to find out and return the number of digits present in a number
   recursively
 */

#include <iostream>
using namespace std;

int count(int n){
	if(n == 0){
		return 0;
	}
	return 1 + count(n / 10);
}

int main(){
	int n = 2343;
	cout << count(n);
}
