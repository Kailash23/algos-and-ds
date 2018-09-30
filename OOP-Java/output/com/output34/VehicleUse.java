package com.output34;

import java.util.Scanner;

public class VehicleUse {

	public static void main(String[] args) {
		Car v = new Car(5,7);
		v.print();		// Which print function to be called is decided at runtime.
	}
}

/*
   Compilation Error :- cannot inherit from final Vehicle
   public class Car extends Vehicle {
                         ^
 */
