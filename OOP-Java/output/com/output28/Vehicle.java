package com.output28;

public class Vehicle {
	protected String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed) {
		this.maxSpeed = maxSpeed;
		this.color = "Blue";
	}

	public void print() {		// print gets override other type of polymorphism
		System.out.println("Vehicle's print function called !");
	}
}
