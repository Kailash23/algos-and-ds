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

	v2 = &c;

	v1->print();
	v2->print();    //polymorphism
}

/*
   Vehicle
   Car
   Vehicle
   Car
 */

 //Virtual functions are those funtion which are present in base class and which are overriden in the derived class

//Virtual keyword helos comiler to take decision at runtime basically it telss to go and check wether v2 is pointing to car class object or vehicle class.
