#include <iostream>
using namespace std;

inline int max(int a, int b){       //Improves readeability and performance
	return (a > b) ? a : b;
}

int main(){
	int a,b;
	a = 10;
	b = 8;
	int c = max (a, b);  //max funtion will copy here in compile time
	cout << c << endl;

	int x,y;
	x = 12;
	y = 34;
	int z = max(x, y);
	cout << z << endl;
}
