package com.output25;

import java.util.Scanner;

public class VehicleUse {

	public static void main(String[] args) {
		Vehicle v = new Car(5,7);
		v.print();		// Which print fucntion to be called is decided at runtime.
	}
}

/*
   Car's print function called !
 */
