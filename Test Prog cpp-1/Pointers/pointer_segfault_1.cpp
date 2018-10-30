#include <iostream>
using namespace std;

int main(){
	int *p = 0;
	cout<<p<<endl;      // 0
	cout<<&p<<endl;     // 0x61ff1c
	cout<<*p<<endl;     // (nothing ie blank) Segfault
	(*p)++;
	cout<<*p<<endl;

	int *q = NULL;      // Segfault
	*q = 1;

	char *str = "foo";      //Segfault
	*str = 'b';
}
