#include<iostream>
using namespace std;

int main(){
	int i = 10;
	int *p = &i;

	int **p2 = &p;
	cout<<p2<<endl;		//0x61ff14
	cout<<&p<<endl;		//0x61ff14

	cout<<p<<endl;		//0x61ff18
	cout<<*p2<<endl;		//0x61ff18
	cout<<&i<<endl;		//0x61ff18

	cout<<i<<endl;		//10
	cout<<*p<<endl;		//10
	cout<<**p2<<endl;		//10
}
