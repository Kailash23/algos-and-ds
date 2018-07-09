#include<iostream>
using namespace std;

int main(){
	int i = 10;
	int *p = &i;

	cout<<p<<endl;
	p+=1;		//This will add 4 bytes to address stored at p
	cout<<p<<endl;
}

//	O/P:- 0x61ff18
//        0x61ff1c
