package com.output18;

public class VehicleUse {
	public static void main(String[] args) {
		Car c = new Car(10);
		System.out.println(c.numGears);
	}
}

/*
	Compile Time Error :-  constructor Vehicle in class Vehicle cannot be applied to
	given types.
	Implicit super constructor Vehicle() is undefined.
	public Car(int numGears){
						    ^

	Explaination : When object of Car class is created its trying to call Vehicle
	class Default constructor ie Vehicle() which is absent. That's why we getting error.
 */
