#include<iostream>
using namespace std;

int main(){
	double a = 10.54;
	double *d = &a;
	d = d + 1;
	cout<<d<<endl;
}
