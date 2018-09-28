package com.temp_vehicle;

import com.vehicle_inheritence.Vehicle;

public class Truck extends Vehicle {
    int maxLoadingCapacity;

    public Truck(int maxSpeed) {
        super(maxSpeed);
    }

    public void print() {
        System.out.println("Truck Capacity : " + maxLoadingCapacity);
        System.out.println("Truck color : " + color);       //Have to make color protected as we are accessing from different package
        System.out.println("Truck Speed : " + getMaxSpeed());
    }
}
