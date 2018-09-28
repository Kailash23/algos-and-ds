package com.basic;

 class Vehicle {
	String color;
	private int maxSpeed;

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

 class Car extends Vehicle {
	int numGears;
	boolean isConvertible;

	public void print() {
		System.out.println("Car color : " + color);
		System.out.println("Car Speed : " + getMaxSpeed());
		System.out.println("Car numGears : " + numGears);
		System.out.println("Car isConvertible : " + isConvertible);
	}
}

public class VehicleUse {

	public static void main(String[] args) {
		Vehicle v = new Vehicle();
		v.color = "Black";
		v.setMaxSpeed(10);
		v.print();

		Car c = new Car();
		c.numGears = 10;
		c.color = "Black";
		c.setMaxSpeed(100);
		c.print();
	}
}
