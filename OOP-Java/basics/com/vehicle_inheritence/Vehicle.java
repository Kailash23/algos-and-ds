package com.vehicle_inheritence;

public class Vehicle {
    protected String color;
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
