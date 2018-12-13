package com.classes_and_objects_basics;

import com.classes_and_objects_basics.Student;
import java.util.Scanner;

public class StudentUse {

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter Roll No: ");
        int rn = s.nextInt();

        System.out.print("Enter name of student: ");
        String sname = s.next();

        Student s1 = new Student("Odesza", 23);     // custom constructor

//        Student s1 = new Student();
//        System.out.println(s1.name);        //null
//        System.out.println(s1.getRollNumber());     //0

        s1.print();

        s1.name = sname;
        s1.setRollNumber(rn);

        System.out.println(s1.name);        //finn
        System.out.println(s1.getRollNumber());      //23

        Student s2 = new Student("Leonidas");
        s2.print();     //Leonidas 0

        s.close();
    }
}

/*
    Enter Roll No: 10
    Enter name of student: Logun
    Odesza 23
    Magnus
    10
    Leonidas 0
 */
