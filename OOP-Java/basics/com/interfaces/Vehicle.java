package com.interfaces;

public class Vehicle implements VehicleInterface {

	public int getMaxSpeed(){
		return 10;
	}

	public void print(){
		System.out.println("Abstract function implemented");
	}
}
