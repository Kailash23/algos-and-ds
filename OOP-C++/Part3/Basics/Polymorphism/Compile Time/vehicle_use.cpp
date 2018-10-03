#include <iostream>
using namespace std;
#include "vehicle_class.cpp"
#include "car_class.cpp"

int main() {
	Vehicle v;

	Car c;

	v.print();
	c.print();

	Vehicle *v1 = new Vehicle;
	Vehicle *v2;

	v2 = &c;		//v2 showuld be base class object and c should be from derived class

	v1->print();
	v2->print();	//Compile time polymorphism
}

/*
   Vehicle
   Car
   Vehicle
   Vehi	cle
 */
