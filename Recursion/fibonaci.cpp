#include <iostream>
using namespace std;

int fib(int n){
	if(n ==0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}

	int smallOutput1 = fib(n-1);
	int smallOutput2 = fib(n-2);
	return smallOutput1 + smallOutput2;
}

int main(){
	cout<<fib(11)<<endl;
}

//0 1 1 2 3 5 8 13 21 34 55 89 144
