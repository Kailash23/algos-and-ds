package com.final_keyword.final_function;

public class Car extends Vehicle {
	int numGears;
	boolean isConvertible;

	public Car(int numGears, int maxSpeed) {
		super(maxSpeed);
		this.numGears = numGears;
		System.out.println("Car Constructor");
	}

	public boolean isConvertible() {
		return isConvertible;
	}

	public void printCar() {		// Car extends from Vehicle class and it has final function print so we can't overide it.
		super.print();
		System.out.println("Car numGears : " + numGears);
		System.out.println("Car isConvertible : " + isConvertible);
	}
}
