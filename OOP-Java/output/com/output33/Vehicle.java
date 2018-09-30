package com.output33;

public class Vehicle {
	protected String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		this.color = "Blue";
	}

	public final void print() {		// final - we can't overide final function
		System.out.println("Vehicle's print function called !");
	}
}
