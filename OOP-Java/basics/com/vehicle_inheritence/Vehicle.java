package com.vehicle_inheritence;

public class Vehicle {
    protected String color;     // If color is friendly ie default you can't use color in
                                //Truck class which is in temp_vehicle package (different package).
    private int maxSpeed;

    public Vehicle(int maxSpeed) {
        this.maxSpeed = maxSpeed;
        System.out.println("Vehicle class constructor is called!");
    }

    public int getMaxSpeed() {
        return maxSpeed;
    }

    public void setMaxSpeed(int maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public void print() {
        System.out.println("Vehicle color : " + color);
        System.out.println("Vehicle Speed : " + maxSpeed);
    }
}

/*
        protected = friendly (within package) + outside package if there is subclass.
        Its more libral then deafult(firendly).

        private < default < protected < public
        
*/
