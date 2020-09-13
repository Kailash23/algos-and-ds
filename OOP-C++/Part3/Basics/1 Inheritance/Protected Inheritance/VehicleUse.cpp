#include <iostream>
using namespace std;

#include "Car.cpp"
#include "Vehicle.cpp"

int main() {
    Vehicle v;
    v.color = "Blue";
    //v.maxSpeed = 100;		//Error: 'maxSpeed' is private  member of Vehicle.
    //v.numTyres = 4;		//Error: 'numTyres' is protected  member of Vehicle.

    Car c;
    //c.color = "Black";	//Error: 'color' become protected after inheritance
    //c.numTyres = 4;		//Error: 'numTyres' is protected within this context
    //c.maxSpeed = 220;		//Error: 'maxSpeed' is protected within this context
    c.numGears = 5;
    c.print();
}

/*
   Main has only access to non inherited public property of the class Vehicle and Car.
 */

/*
   NumTyres : -679974545
   Color :
   Num gears : 5
 */
