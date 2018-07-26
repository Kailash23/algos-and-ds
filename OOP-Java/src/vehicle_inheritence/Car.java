package vehicle_inheritence;

public class Car extends Vehicle {
    int numGears;
    boolean isConvertible;

    public Car(int numGears, int maxSpeed) {
        super(maxSpeed);     //when super class has no default constructor
        this.numGears = numGears;
        System.out.println("Car constructor is called!");
    }

    public boolean isConvertible() {
        return isConvertible;
    }

    public void print() {
        super.print();      //Calls the print function of Car class
        System.out.println("Car numGears : " + numGears);
        System.out.println("Car isConvertible : " + isConvertible);
    }
}

//  Modifiers which are not allowed in front of class. 1. private 2. protected