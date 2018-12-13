package com.interfaces;

public class VehicleUse {
	public static void main(String args[]){
		Vehicle v = new Vehicle();
		v.print();

		Car c = new Car();
		System.out.println(c.getCompany());
	}
}

/*
   Abstract function implemented
   Tesla
 */

/*
   Interface is basically a class with all abstract function.
 */

/*
   Interfaces can contain only constants and method signatures, but no implementation.

   Interfaces cannot be instantiated. They can only be implemented by an implementing class or extended by another interface.

   A class that implements an interface must provide implementation to all the methods that are declared in the interface.

   Interfaces can be used as reference type for the object of an implementing class.

   An interface can be extended by another interface.
 */


/*
	An interface can extend another interface.

	A non-abstract class which is implementing an interface must implement all
	the methods of the interface.

	An interface is a solution for multiple inheritance in java.

	An interface can extend another interface.

*/
