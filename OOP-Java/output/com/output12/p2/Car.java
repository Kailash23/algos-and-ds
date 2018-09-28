package com.output12.p2;

import com.output12.p1.Vehicle;

class Car extends Vehicle {
    public static void main(String args[]) {
        Car c = new Car();
        c.name = "Ferrari";
        System.out.println(c.name);
    }
}

/*
   Ferrari
 */
