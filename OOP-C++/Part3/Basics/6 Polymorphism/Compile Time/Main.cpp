#include <iostream>
using namespace std;

#include "Car.cpp"
#include "Vehicle.cpp"

int main() {
    Vehicle v;
    Car c;

    v.print();
    c.print();

    Vehicle *v1 = new Vehicle; // Dynamically
    Vehicle *v2;               // Using v2 we can only access those property that are in Vehicle.
                               // Because v2 pointer is of Vehicle type.

    v2 = &c; // v2 should be base class object and c should be from derived class.
        // Base class pointer pointing to child class object.
    v1->print();
    v2->print(); // Compile time polymorphism - Vehicle's print function will call.
}

/*
   Vehicle
   Car
   Vehicle
   Vehicle
 */

/*
Compile Time polymorphism : Taking decision at compile time.

1. Function Overloading

	int test(int a, int b){

	}

	int test(int a){

	}

	int test(){

	}

2. Operator Overloading

	2 + 3 			// = 5		(int)
	3.5 + 1.5		// 5.0		(double)
	'a' + 'b'		// 97 + 98		(char)
	c1 + c2 		// c1, c2 are complex numTyres		(Complex Number)

	One opperator (+) multiple behaviour.

3. Method Overriding / Function Overriding

	When Child class overide Base class function.

*/

/*
   Base class pointer is pointed to derived class.
 */
