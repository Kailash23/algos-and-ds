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
   Compilation Error: request for member 'print' is ambiguous
   b.print();
 */
