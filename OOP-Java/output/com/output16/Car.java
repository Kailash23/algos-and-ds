package com.output16;

public class Car extends Vehicle {
	int numGears;
	boolean isConvertible;

	public void print() {
		super.print();		// first print vehicle print then mine (parent's print)
		System.out.println("Car numGears : " + numGears);
		System.out.println("Car isConvertible : " + isConvertible);
	}
}
