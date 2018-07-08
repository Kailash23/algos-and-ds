#include<iostream>
using namespace std;

int main(){
	int *p = 0;
	cout<<p<<endl;		// 0
	cout<<&p<<endl;		// 0x61ff1c
	cout<<*p<<endl;		// (nothing ie blank)
	(*p)++;
	cout<<*p<<endl;

	int *q = NULL;
	*q = 1;

	char *str = "foo";
	*str = 'b';
}
