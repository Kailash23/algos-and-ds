#include <iostream>
using namespace std;

int main(){
	int a = 10;
	int *ptr = &a;
	cout<<*ptr<<endl;       // Value at address inside ptr
	cout<<ptr<<endl;        // Address inside ptr
	cout<<&ptr<<endl;       // Address of ptr
}
