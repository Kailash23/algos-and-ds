/*
   Object creation of a class having private constructor
 */

package com.private_constructor_demo;

class Vehicle {

    private Vehicle(){
        System.out.println("constructor of Vehicle");
    }

    public static Vehicle getInstance() {
        return new Vehicle();
    }
}

public class Car {
    public static void main(String[] args) {
        Vehicle v = Vehicle.getInstance();
    }
}

/*
   constructor of Vehicle
 */
