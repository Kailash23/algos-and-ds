package com.output27;

import java.util.Scanner;

public class VehicleUse {

	public static void main(String[] args) {
		Vehicle v = new Car(5,7);
		v.print();		// Which print function to be called is decided at runtime.
	}
}

/*
   Vehicle's print function called !
 */

/*
   At first it will search in class Car whether it has print function or not. If it doesn't
   have print func then Vehicle print's fucntion is called.
 */
