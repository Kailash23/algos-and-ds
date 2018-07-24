#include <iostream>
using namespace std;

void square(int *p,int a){
	p = &a;
	*p = (*p) * (*p);
}

int main(){
	int a = 10;
	square(&a,a);
	cout << a << endl;      //10
}
