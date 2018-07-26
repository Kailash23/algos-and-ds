package p2;

import p1.Vehicle;

class Car extends Vehicle {

    void print() {
        System.out.println(gameName);  //we can use it in sub class
    }

    public static void main(String[] args) {
        Vehicle g = new Vehicle();
       // g.gameName = "Basketball";      //Error: gameName has protected access in p1.Vehicle
        Car s = new Car();
        s.gameName = "Basketball";
    }
}
