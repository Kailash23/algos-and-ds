#include<iostream>
using namespace std;

int main(){
	int a[5] = {1,2,3,4,5};
	cout<<*a<<endl;
	cout<<a[1]<<endl;
	cout<<*(a+1)<<endl;
	cout<<1[a]<<endl;		//rare
	cout<<a<<endl;		//0x61ff0c
	cout<<&a<<endl;		//0x61ff0c same as above
	cout<<sizeof(a)<<endl;
	//a=a+3;		//Will show error array cant be reassigned.
	//cout<<a<<endl;
	int *p=a;
	cout<<p<<endl;
}
