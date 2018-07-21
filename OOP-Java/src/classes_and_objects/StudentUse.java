package classes_and_objects;

import java.util.Scanner;

public class StudentUse {

    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        System.out.print("Enter Roll No: ");
        int rn = s.nextInt();

        System.out.print("Enter name of student: ");
        String sname = s.next();

        Student s1 = new Student();
        s1.name = sname;
        s1.rollNumber = rn;

        System.out.println(s1.rollNumber);
        s.close();

    }
}
