package com.generics.bound_generic_type.Part2;

import com.generics.bound_generic_type.Vehicle;

/*
   Bound - Only Vehicle subclasses
   Very Restrictive.
 */

public class Print {
	public static<T extends Vehicle> void printArray(T a[]){
		for(int i = 0 ; i < a.length; i++){
			System.out.print(a[i]);
			System.out.print(" ");
		}
		System.out.println();
	}

	public static void main(String args[]){

		Vehicle v[] = new Vehicle[3];		// Vehicle is object subclass
		for(int i = 0; i < 3; i++){
			v[i] = new Vehicle(220);		// max_speed = 220
		}
		printArray(v);
	}
}

/*
   Vehicle Parameterized Constructor
   Vehicle Parameterized Constructor
   Vehicle Parameterized Constructor
   com.final_keyword.final_function.Vehicle@3b192d32 com.final_keyword.final_function.Vehicle@16f65612 com.final_keyword.final_function.Vehicle@311d617d
 */
