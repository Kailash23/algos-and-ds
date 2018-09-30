package com.output34;

public final class Vehicle {	// final class - we can't inherit final class.
	protected String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		this.color = "Blue";
	}

	public void print() {		// final - we can't overide final function
		System.out.println("Vehicle's print function called !");
	}
}
