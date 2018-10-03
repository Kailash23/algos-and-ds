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
   Virtual Inheritance

   Output :

   Vehicle's default constructor
   Car's default constructor
   Truck's constructor
   Bus's constructor
   Bus's distructor
   Truck's destructor
   Car's distructor
   Vehicle's destructor
 */


/*
   Normal Inheritance

   Output :

   Vehicle's default constructor
   Car's default constructor
   Vehicle's default constructor
   Truck's constructor
   Bus's constructor
   Bus's distructor
   Truck's destructor
   Vehicle's destructor
   Car's distructor
   Vehicle's destructor
 */

/*
   Vehicle class is virtual base class of Car and Truck.
   Vehicle class constructor will be called for only one time as it is called by
   Bus instead of Car and Truck.
 */
