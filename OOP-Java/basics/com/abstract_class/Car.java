package com.abstract_class;

import com.abstract_class.Vehicle;

public abstract class Car extends Vehicle {
	int numGears;
	boolean isConvertible;

	public Car(){
		super(100);
		System.out.println("Car's Default Constructor");
	}

	public Car(int numGears, int maxSpeed) {
		super(maxSpeed);
		this.numGears = numGears;
		System.out.println("Car's Parameterized Constructor");
	}

	@Override
	public boolean isMotarized() {
		return true;
	}

	public boolean isConvertible() {
		return isConvertible;
	}

	public void print() {
		super.print();
		System.out.println("Car numGears : " + numGears);
		System.out.println("Car isConvertible : " + isConvertible);
	}
}

/*
   If car extends an abstract clas it has 2 options.
   either to declare itself abstract.
   or to to complete the incompleteness by overiding abstract function.
 */
