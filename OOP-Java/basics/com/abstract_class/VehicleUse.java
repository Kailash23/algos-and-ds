package com.abstract_class;

import com.abstract_class.*;

public class VehicleUse {
	public static void main(String[] args) {
		BMW b = new BMW(10);
		System.out.println(b.getCompany());
	}
}


/*
   Vehicle Constructor
   Car's Default Constructor
   BMW
 */

/*
   We can't create object of a abstract class.
   We can't do this Vehicle v = new Vehicle(); because Vehicle is abstract class
   But we can do this Vehicle v = new Car(); because Car is not abstract
 */
