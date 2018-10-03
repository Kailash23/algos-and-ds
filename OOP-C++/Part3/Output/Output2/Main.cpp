#include <iostream>
using namespace std;

#include "Vehicle.cpp"
#include "Car.cpp"
#include "Truck.cpp"
#include "Bus.cpp"

int main() {
	Bus b;
	b.print();
}

/*
   Compilation Error: request for member 'print' is ambiguous
   b.print();
 */
