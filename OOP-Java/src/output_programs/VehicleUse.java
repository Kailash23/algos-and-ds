package output_programs;

class Vehicle {
    void print() {
        System.out.print("Vehicle class");
    }
}

class Truck extends Vehicle {
    void print() {
        System.out.print("Car class ");
    }
}

 public class VehicleUse {
    public static void main(String[] args) {
        Vehicle obj1 = new Truck();
        obj1.print();

        Vehicle obj2 = new Vehicle();
        obj2.print();
    }
}