package com.vehicle_inheritence;

import com.vehicle_inheritence.Vehicle;
import com.vehicle_inheritence.Car;

public class VehicleUse {
    public static void main(String[] args) {
        System.out.println();
        Vehicle v = new Vehicle(100);      //Vehicle constructor is called.
        v.color = "Grey";
        v.print();
        System.out.println();

        System.out.println();
        Vehicle d = new Car(10, 20); //because Car is sub-class of Vehicle
        // boolean ans =  d.isConvertible();        //d is point to Vehicle and isConvertible is from Car class
        //(So isConvertible called on Vehicle reference will be rejected by compiler <compiler time decision>)
        boolean ans = ((Car) d).isConvertible();
        System.out.println(ans);
        d.print();  //Vehicle's print function will call then Car's print function will call. (Which function to be called? Is a run time decision)
        System.out.println();

        System.out.println();
        Car c = new Car(10, 20);      //Vehicle as well as Car constructor is called.
        c.color = "Black";
        c.setMaxSpeed(100);
        c.print();
        System.out.println();
    }
}

/*
   When we create derived class object parent class object is also formed.
 */

/*

    Vehicle class constructor is called!
    Vehicle color : Grey
    Vehicle Speed : 100


    Vehicle class constructor is called!
    Car constructor is called!
    false
    Vehicle color : null
    Vehicle Speed : 20
    Car numGears : 10
    Car isConvertible : false


    Vehicle class constructor is called!
    Car constructor is called!
    Vehicle color : Black
    Vehicle Speed : 100
    Car numGears : 10
    Car isConvertible : false

 */


/*
   A class can extend only one class.

   A super class reference can refer to a sub class object.

   If reference is super class and object is of sub class then calling an instance
   method on it will result in execution of the method defined in sub class.

   An overridden method has same signature and return type (or compatible with the
   return type) as that of super class method.

   We can hide a static method defined in super class by defining a static method
   having same signature or return type (or compatible with the return type) as that
   of super class method.

   When a sub class constructor runs the super class constructor also runs. This is
   called constructor chaining.

 */

 /*
    Compile Time And Runtime Polymorphism

    Vehicle v; -> reference created (v will point to Vehicle)
    v can point to any class which is subclass of Vehicle.
    eg - Vehicle v = new Car();

    If car has isConvertible function
    v can't access that it can only access Vehicle specific methods
    we can use v.print() cause Vehicle and Car both have print function.
    v.print() will print Car's print function  because it is decided in runtime

    If we use v.isConvertible it will not compile because Vehicle have no function named as isConvertible

    If the function parent in both super and subclass. whome to execute will
    be decided at runtime.

    Method overridden is another type of Polymorphism
 */
