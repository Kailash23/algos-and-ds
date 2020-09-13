#include <iostream>
using namespace std;

#include "Bus.cpp"
#include "Car.cpp"
#include "Truck.cpp"
#include "Vehicle.cpp"

int main() {
    Bus b;
    b.print();
}

/*
   Vehicle's default constructor
   Car's default constructor
   Vehicle's default constructor
   Truck's constructor
   Bus's constructor
   Bus									// b.print()
   Bus's destructor
   Truck's destructor
   Vehicle's destructor
   Car's destructor
   Vehicle's destructor
 */

/*
   We got print() on Bus class. So compiler don't have to look in parent class.
 */
