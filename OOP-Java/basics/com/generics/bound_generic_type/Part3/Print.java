package com.generics.bound_generic_type.Part3;

import com.generics.bound_generic_type.Vehicle;
import com.generics.bound_generic_type.Student;
import com.generics.bound_generic_type.PrintInterface;

/*
  Bound - Only classes that implements PrintInterface
 */

public class Print {
	public static<T extends PrintInterface> void printArray(T a[]){
		/*
		   Generic bound (interface and class) we used extend keyword. Those T's which implements PrintInterface,
		   then we are sure they have print function.
		 */
		for(int i = 0 ; i < a.length; i++){
			a[i].print();
			System.out.println();
		}
		System.out.println();
	}

	public static void main(String args[]){

		Vehicle v[] = new Vehicle[3];		// Vehicle is object subclass
		for(int i = 0; i < 3; i++){
			v[i] = new Vehicle(220);		// max_speed = 220
		}
		System.out.println();
		printArray(v);

		Student s1[] = new Student[3];
		for(int i = 0; i < 3 ; i++){
			s1[i] = new Student(3);
		}
		System.out.println();
		printArray(s1);
	}
}

/*
   Creating Vehicle 0...
   Creating Vehicle 1...
   Creating Vehicle 2...

   Vehicle Color : White
   Vehicle Speed : 220

   Vehicle Color : White
   Vehicle Speed : 220

   Vehicle Color : White
   Vehicle Speed : 220


   Creating Student 0...
   Creating Student 1...
   Creating Student 2...

   Student's rollNumber: 3

   Student's rollNumber: 3

   Student's rollNumber: 3
 */
