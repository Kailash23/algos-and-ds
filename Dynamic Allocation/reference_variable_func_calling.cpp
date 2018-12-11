#include <iostream>
using namespace std;

void increment(int& n){     //Value passed by reference instead of passed by value.
	n++;
}

int main(){
	int i = 10;
	increment(i);       //i and n now share same memory
	cout << i << endl;
}


//If passed by value then output will be 10
