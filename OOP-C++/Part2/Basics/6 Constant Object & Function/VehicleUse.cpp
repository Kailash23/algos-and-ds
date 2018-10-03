#include <iostream>
using namespace std;

#include "Vehicle.cpp"

int main(){
	Vehicle const v1(100,20);
	cout << v1.getSpeed() << endl;		// Compiler don't allow call from constant objects
	cout << v1.getRegId() << endl;		// You can only constant function through constant objects
}

/*
   We can't call normal function from constant object. we can only call constant function
   from constant object.

   Constant function : Which doesn't change any property of current object.

   If a member function does not alter any data in the class, that may be declared as
   constant member function
 */
