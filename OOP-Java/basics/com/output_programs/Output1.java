package com.output_programs;

class Student {
    String name;
    int rollNo;

    Student(int num) {
        rollNo = num;
    }

    public void print() {
        System.out.println(name + " " + rollNo);
    }
}

public class Output1 {
    public static void main(String args[]){
//        Student s = new Student();        //Compilation error
//        s.rollNo = 15;
//        s.print();
    }
}
