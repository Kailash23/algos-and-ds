package com.output33;

import java.util.Scanner;

public class VehicleUse {

	public static void main(String[] args) {
		Car v = new Car(5,7);
		v.print();		// Which print function to be called is decided at runtime.
	}
}

/*
   Compilation Error :- print() in Car cannot override print() in Vehicle
        public void print() {
                    ^
   overridden method is final
 */
