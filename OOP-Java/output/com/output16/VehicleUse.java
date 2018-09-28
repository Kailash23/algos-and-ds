package com.output16;

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

/*
   Vehicle color : Black
   Vehicle Speed : 10
   Vehicle color : Black
   Vehicle Speed : 100
   Car numGears : 10
   Car isConvertible : false
 */
