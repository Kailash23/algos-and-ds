package com.output25;

public class Car extends Vehicle {
	int numGears;
	boolean isConvertible;

	public Car(int numGears, int maxSpeed) {
		super(maxSpeed);
		this.numGears = numGears;
		this.isConvertible = true;
	}

	public boolean isConvertible() {
		return isConvertible;
	}

	public void print() {
		System.out.println("Car's print function called !");
	}
}
