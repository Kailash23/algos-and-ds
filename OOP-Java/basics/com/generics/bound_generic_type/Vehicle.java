package com.generics.bound_generic_type;

import com.generics.bound_generic_type.PrintInterface;

public class Vehicle implements PrintInterface {
	protected String color;
	private int maxSpeed;
	private static int vehicleCount;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		this.color = "White";
		System.out.println("Creating Vehicle " + vehicleCount + "...");
		vehicleCount++;
	}

	public int getMaxSpeed() {
		return maxSpeed;
	}

	public void setMaxSpeed(int maxSpeed) {
		this.maxSpeed = maxSpeed;
	}

	public void print() {
		System.out.println("Vehicle Color : " + color);
		System.out.println("Vehicle Speed : " + maxSpeed);
	}
}
