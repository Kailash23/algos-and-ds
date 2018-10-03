#include <iostream>
using namespace std;

#include "Vehicle.cpp"
#include "Car.cpp"

int main() {
	//Vehicle v;		// Can't create object of abstract class.
	Car c;
}

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
