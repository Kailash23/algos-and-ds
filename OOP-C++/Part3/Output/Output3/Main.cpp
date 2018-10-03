#include <iostream>
using namespace std;

#include "Vehicle.cpp"
#include "Car.cpp"
#include "Truck.cpp"
#include "Bus.cpp"

int main() {
	Bus b;
	b.Truck :: print();
	b.Car :: print();
}

/*
   Vehicle's default constructor
   Car's default constructor
   Vehicle's default constructor
   Truck's constructor
   Bus's constructor
   Vehicle
   Car
   Bus's destructor
   Truck's destructor
   Vehicle's destructor
   Car's destructor
   Vehicle's destructor
 */

/*
   We got print() on Bus class. So compiler don't have to look in parent class.
 */
