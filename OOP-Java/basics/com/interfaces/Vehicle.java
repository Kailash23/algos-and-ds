package com.interfaces;

public class Vehicle implements VehicleInterface {

	public int getMaxSpeed(){
		return 10;
	}

	public void print(){
		System.out.println("Abstract function implemented");
	}
}

/*
	Interface - Purely abstract class
	An interface can extend another interface
	Only include final static data member

	We have 2 options after implementing VehicleInterface
	> either declare class as abstract
	> Or implement all the function
*/
