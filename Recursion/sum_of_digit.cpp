/*
Sum of digits (recursive)

Write a recursive function that returns the sum of the digits of a given integer.
*/

#include<iostream>
using namespace std;

//1
int sumOfDigits(int n){
	int sum = 0;
	if(n<=9){
		return sum+=n;
	}
 	sum = sum + (n%10);
	return sum + sumOfDigits(n/10);
}

// //2	Coding Ninjas
// int sumOfDigits(int n){
// 	if(n<=9){
// 		return n;
// 	}
// 	return n%10 + sumOfDigits(n/10);
// }

int main(){
	int i = 12345;
	cout<<sumOfDigits(i);
}
