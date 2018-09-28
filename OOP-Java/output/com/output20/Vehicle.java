package com.output20;

public class Vehicle {
	String color;
	private int maxSpeed;

	public Vehicle(int maxSpeed){
		this.maxSpeed = maxSpeed;
		System.out.println("Vehicle's Constructor");
	}

	public Vehicle(){
		System.out.println("Vehicle's Default Constructor");
	}

	public int getMaxSpeed(){
		return maxSpeed;
	}
}
