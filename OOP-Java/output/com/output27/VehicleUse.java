package com.output27;

import java.util.Scanner;

public class VehicleUse {

	public static void main(String[] args) {
		Vehicle v = new Car(5,7);		// Polymophism - object formed is of car type.
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

/*
   If we use,
   		Car c = new Car();
   and use c.print() then car's print function will be called
   beacuse Car's print overided the Vehicle class's print fucntion.
 */
