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
	v2->print();    // Polymorphism - Runtime
}

/*
   Vehicle
   Car
   Vehicle
   Car
 */

/*
   Virtual functions are those function which are present in base class and
   which are overriden in the derived class.
 */

/*
   Virtual keyword helps compiler to take decision at runtime basically it tells to
   go and check whether v2 is pointing to Car class object or Vehicle class object.
 */

/*
   To achieve runtime polymorphism we need to take help of virtual function.
 */
