#include <iostream>
using namespace std;

#include "Bus.cpp"
#include "Car.cpp"
#include "Truck.cpp"
#include "Vehicle.cpp"

int main() {
    Bus b;
    b.print();
    b.Car ::print();
    b.Truck ::print();
    //b.Vehicle :: print();		// This will give error: 'Vehicle' is an ambiguous base of 'Bus'
}

/*
   Vehicle's default constructor
   Car's default constructor
   Vehicle's default constructor
   Truck's constructor
   Bus's constructor
   Bus
   Car
   Truck
   Bus's distructor
   Truck's destructor
   Vehicle's destructor
   Car's distructor
   Vehicle's destructor
 */
