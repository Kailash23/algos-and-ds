#include <iostream>
using namespace std;
#include "vehicle_class.cpp"
#include "car_class.cpp"

int main(){
	Vehicle v;
	v.color = "Blue";
	//v.maxSpeed = 100;		//Error: maxSpeed' is private within this context
	//v.numTyres = 4;		//Error: numTyres' is protected within this context

	Car c;
	c.color = "Black";
	//c.numTyres = 4;		//numTyres' is protected within this context
	c.numGears = 5;
}
