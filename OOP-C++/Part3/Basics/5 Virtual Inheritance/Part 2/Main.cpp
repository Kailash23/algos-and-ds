#include <iostream>
using namespace std;

#include "Vehicle.cpp"
#include "Car.cpp"
#include "Truck.cpp"
#include "Bus.cpp"

int main() {
	Bus b;
}

/*
   Vehicle class constructor is called by bus class not by call and truck that's virtual inheritance.
 */

/*
   Vehicle's parameterized constructor : 5
   Car's default constructor
   Truck's constructor
   Bus's constructor
   Bus's distructor
   Truck's destructor
   Car's distructor
   Vehicle's destructor
 */

/*
   This,
   Vehicle's parameterized constructor : 5
   Shows that Bus had called Vehicle's parameterized constructor. As we explicitly
   passed 5 in Bus class.
 */
