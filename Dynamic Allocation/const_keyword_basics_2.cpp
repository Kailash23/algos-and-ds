#include <iostream>
using namespace std;

int main(){
	int p = 5;
	int const *q = &p;
	//(*q)++;       Can't do this
}
