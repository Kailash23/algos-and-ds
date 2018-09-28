package com.output26;

import java.util.Scanner;

public class VehicleUse {

	public static void main(String[] args) {
		Vehicle v = new Car(5,7);
		boolean ans = v.isConvertible();  // We can use only Vehicle specific things, here isConvertible()
										  // is specific to car so we will get error.  
		System.out.println(ans);
	}
}


/*
   error: cannot find symbol
   boolean ans = v.isConvertible();
   				   ^
 */
