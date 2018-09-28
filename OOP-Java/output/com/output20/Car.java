package com.output20;

public class Car extends Vehicle {
	int numGears;
	boolean isConvertible;

	public Car(int numGears){
		this.numGears = numGears;
		System.out.println("Car's Constructor");
	}
}
