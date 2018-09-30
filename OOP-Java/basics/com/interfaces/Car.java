package com.interfaces;

public class Car extends Vehicle implements  CarInterface {

	@Override
	public int getMaxSpeed() {
		return 220;
	}

	@Override
	public String getCompany(){
		return "Tesla";
	}

	@Override
	public void print(){
		System.out.println("");
	}
}
