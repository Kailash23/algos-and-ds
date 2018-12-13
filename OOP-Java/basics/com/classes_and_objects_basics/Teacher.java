package com.classes_and_objects_basics;

public class Teacher {
    private final int empId;        //also called data member
    // final data members can be initialized as soon as they are declared
    // Or they can be initialized in constructor.

    /*
        final keyword use :
        Variable - to make constant ie, no reassign
        Method - to prevent overriding in subclasses.
        Class- to prevent subclassing.
    */

    String name;
    private static int numTeachers;     //static data member

    /*
        static keyword is bound to the class and not
        to an individual object, thus we can’t make
        constructors static.
     */


//    public Teacher(){        //Useless all student will have same emp id
//        empId = 100;
//    }

//    public Teacher(String n){        //Useless all object will have same emp id
//        name = n;
//        empId = 10;
//    }

//    public Teacher(String n, int ei) {        // Without this keyword
//        name = n;
//        empId = ei;
//    }

    public Teacher(String name, int empId) {
//        System.out.println("1 :"+ this);       //"this" is the reference to the class

        this.name = name;       //this is used to distinguish between local variable and data member
        this.empId = empId;
        numTeachers++;
    }

//    public void setEmpid(int ei){        //Useless we cant set final field again
//        if(ei <= 0){
//            return;
//        }
//        empId = ei;
//    }

    public static int getNumTeachers() {        //static function don't depend on object
        return numTeachers;           //for accessing static data member
    }

    public int getEmpId() {
        return empId;
    }

    void print() {
        System.out.println(name + " " + empId + " " + numTeachers);
    }
}

/*
   default (firendly) - within package
   private - only within class
   public - anywhere
 */
