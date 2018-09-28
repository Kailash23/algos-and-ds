package com.output19;

public class Car extends Vehicle {
	int numGears;
	boolean isConvertible;

	public Car(int numGears){
		super(7);
		this.numGears = numGears;
		System.out.println("Car's Constructor");
	}
}
