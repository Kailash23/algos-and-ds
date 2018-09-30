package com.generics.bound_generic_type;

import com.generics.bound_generic_type.PrintInterface;

public class Student implements PrintInterface {

	int rollNumber;
	private static int studentCount;

	public Student(int rollNumber){
		this.rollNumber = rollNumber;
		System.out.println("Creating Student " + studentCount + "...");
		studentCount++;
	}

	public void print() {
		System.out.println("Student's rollNumber: " + rollNumber);
	}
}
