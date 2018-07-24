#include <iostream>
using namespace std;

void print(int *p){
	cout<<*p<<endl;
}

void incrementPointer(int *p){
	p = p + 1;      //very important (copy of pointer is made)
}

void increment(int *p){
	(*p)++;         //Going to address and make the change.
}

int main(){
	int i = 10;
	int *p = &i;

	print(p);       //10

	cout<<p<<endl;      //0x61ff18
	incrementPointer(p);        //changes will not reflected
	cout<<p<<endl;      //0x61ff18

	cout<<*p<<endl;     //10
	increment(p);
	cout<<*p<<endl;     //10

	cout<<*p<<endl;     //10
	increment(&i);
	cout<<*p<<endl;     //10


}
