package com.output21;

public class Vehicle {
	protected String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		System.out.println("Vehicle Constructor");
	}

	public int getMaxSpeed() {
		return maxSpeed;
	}
}
