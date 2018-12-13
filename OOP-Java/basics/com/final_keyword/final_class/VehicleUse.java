package com.final_keyword.final_class;

import java.util.Scanner;
import com.final_keyword.final_class.Vehicle;

public class VehicleUse {

	public static void main(String[] args) {
		Vehicle v = new Car(10,20);
		v.print();
	}
}

/*
   Compilation Error : cannot inherit from final Vehicle

   public class Car extends Vehicle{
 */

/*
   Function - Any subclass cant override this function.
   Class - No other class can inherit this class.
 */
