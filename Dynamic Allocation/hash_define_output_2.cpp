#include <iostream>
using namespace std;

#define SQUARE(x) x*x

int main(){
	int x = 36 / SQUARE(6);
	cout << x;      //36
	return 0;
}
