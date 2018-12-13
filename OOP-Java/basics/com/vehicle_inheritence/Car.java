package com.vehicle_inheritence;

public class Car extends Vehicle {
    int numGears;
    boolean isConvertible;

    public Car(int numGears, int maxSpeed) {
        super(maxSpeed);
        // If we made Car class object then it will also make Vehicle class object inside it.
        // When we call derived class constructor it also call super class constructor
        // First super class constructor after that derived class
        // This will call for Vehicle() constructor ie default but there is no default constructor
        // We have parametrized constructor of vehicle with maxSpeed as parameter.
        // So we can explicitly call Vehicle parametrized constructor using super keyword
        // and will pass max speed in it.
        // super(maxSpeed) - this should be first line
        this.numGears = numGears;
        System.out.println("Car constructor is called!");
    }

    public boolean isConvertible() {
        return isConvertible;
    }

    public void print() {
        super.print();      // Calls the print function of Vehicle class (parent class)
        System.out.println("Car numGears : " + numGears);
        System.out.println("Car isConvertible : " + isConvertible);
    }
}

//  Modifiers which are not allowed in front of class. 1. private 2. protected
//
