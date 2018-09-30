package com.generics.bound_generic_type.Part1;

import com.generics.bound_generic_type.Vehicle;

/*
   No Bound
 */

public class Print {
	public static<T> void printArray(T a[]){
		for(int i = 0 ; i < a.length; i++){
			System.out.print(a[i]);
			System.out.print(" ");
		}
		System.out.println();
	}

	public static void main(String args[]){
		Integer a[] = new Integer[5];
		for(int i = 0; i < 5; i++){
			a[i] = i + 1;
		}

		String s[] = new String[5];
		for(int i = 0; i < 5; i++){
			s[i] = "abc";
		}
		printArray(a);
		printArray(s);
	}
}

/*
   1 2 3 4 5
   abc abc abc abc abc
 */
