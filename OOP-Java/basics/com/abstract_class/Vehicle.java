package com.abstract_class;

public abstract class Vehicle {		// Have to make class abstract cause it has abstract funtion.
	protected String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		System.out.println("Vehicle Constructor");
	}

	// By making this function abstract we are forcing sub class to overide this function.
	public abstract boolean isMotarized();		// Vehicle is a abstract class cause it has abstract function isMotarised();

	public abstract String getCompany();

	public int getMaxSpeed() {
		return maxSpeed;
	}

	public void setMaxSpeed(int maxSpeed) {
		this.maxSpeed = maxSpeed;
	}

	public void print() {
		System.out.println("Vehicle color : " + color);
		System.out.println("Vehicle Speed : " + maxSpeed);
	}
}

/*
	We can't create object of abstract class. Cause its an incomplete class.
*/
