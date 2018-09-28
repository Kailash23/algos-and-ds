package com.output25;

public class Vehicle {
	protected String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		this.color = "Blue";
	}

	public void print() {
		System.out.println("Vehicle's print function called !");
	}
}
