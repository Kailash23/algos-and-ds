/*
   Object creation of a class having private constructor
 */

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
