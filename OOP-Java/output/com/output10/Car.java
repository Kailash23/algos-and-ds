// Both classes are in same package.

package com.output10;

class Vehicle{
    String color;
    private int id;
}

public class Car {
    public static void main(String[] args) {
        Vehicle v = new Vehicle();
        v.color = "white";
        v.id = 101;
        System.out.println(v.color + " " + v.id);
    }
}

/*
   Compilation Error :

   id has private access in Vehicle
        v.id = 101;
         ^
   id has private access in Vehicle
     System.out.println(v.color + " " + v.id);
 */
