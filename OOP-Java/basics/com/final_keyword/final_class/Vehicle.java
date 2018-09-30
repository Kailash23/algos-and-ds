package com.final_keyword.final_class;

public final class Vehicle {		// If a class is declared as final then we can't inherit it.
	protected String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		System.out.println("Vehicle Parameterized Constructor");
	}

	public int getMaxSpeed() {
		return maxSpeed;
	}

	public void setMaxSpeed(int maxSpeed) {
		this.maxSpeed = maxSpeed;
	}

	public void print() {		// Subclass can't overide this function cause we declared it as final.
		System.out.println("Vehicle Color : " + color);
		System.out.println("Vehicle Speed : " + maxSpeed);
	}
}
