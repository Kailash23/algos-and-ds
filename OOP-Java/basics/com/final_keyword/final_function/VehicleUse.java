package com.final_keyword.final_function;

import java.util.Scanner;
import com.final_keyword.final_function.Vehicle;

public class VehicleUse {

	public static void main(String[] args) {

		Vehicle v = new Car(10,20);		// Car type object is made
		v.print();		// Vehicle print function called

		System.out.println();

		Vehicle v1 = new Vehicle(10);
		v1.print();
	}
}

/*
   Vehicle Parameterized Constructor
   Car Constructor
   Vehicle Color : null
   Vehicle Speed : 20

   Vehicle Parameterized Constructor
   Vehicle Color : null
   Vehicle Speed : 10
 */
