// Both classes are in same package.

package com.output5;

class Student{
    String name;
    int rollNo;
    Student(int num){
    rollNo = num;
    }
    public void print(){
    System.out.print(name + " " + rollNo + " ");
    }
}

public class StudentUse {
    public static void main(String[] args) {
        Student s = new Student();      // <-
        s.rollNo = 15;
        s.print();
    }
}

/*
   Compilation Error
   constructor Student in class Student cannot be applied to given types
 */
