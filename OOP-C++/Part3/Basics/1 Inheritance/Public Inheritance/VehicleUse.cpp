#include <iostream>
using namespace std;

#include "Vehicle.cpp"
#include "Car.cpp"

int main(){
	Vehicle v;
	v.color = "Blue";
	//v.maxSpeed = 100;		//Error: 'maxSpeed' is private  member of Vehicle
	//v.numTyres = 4;		//Error: 'numTyres' is protected member of Vehicle

	Car c;
	c.color = "Black";
	//c.numTyres = 4;		//Error: 'numTyres' is protected within this context
	//c.maxSpeed = 220;		//Error: 'maxSpeed' is protected within this context
	c.numGears = 5;
	c.print();
}

/*
   Main has only access to public property (inherited and non inherited) of the both class Vehicle and Car.
 */

/*
   NumTyres : 897855454
   Color : Black
   Num gears : 5
 */

/*
   Protected and Private are not accessible outside of the classes.
 */
