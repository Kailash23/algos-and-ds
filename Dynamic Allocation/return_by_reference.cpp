#include <iostream>
using namespace std;

int& f1(int n){     //Bad practice
	int a = n;      //reference to local variable 'a' returned
	return a;
}

int* f2(){      //Bad practice
	int i = 10;     //address of local variable 'i' returned
	return &i;
}

int main(){
	int i = 10;
	int& k = f1(i);

	int *p = f2();
	cout<<p;
}
