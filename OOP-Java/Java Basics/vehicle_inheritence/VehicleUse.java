package vehicle_inheritence;

public class VehicleUse {
    public static void main(String[] args) {
        System.out.println("#####################");
        Vehicle v = new Vehicle(100);      //Vehicle constructor is called.
        v.color = "Grey";
        v.print();
        System.out.println("#####################");

        System.out.println("*******************");
        Vehicle d = new Car(10, 20); //because Car is sub-class of Vehicle
        // boolean ans =  d.isConvertible();        //d is point to Vehicle and isConvertible is from Car class
        //(So isConvertible called on Vehicle reference will be rejected by compiler <compiler time decision>)
        boolean ans = ((Car) d).isConvertible();
        System.out.println(ans);
        d.print();  //Vehicle's print function will call then Car's print function will call. (Which function to be called? Is a run time decision)
        System.out.println("*******************");

        System.out.println("#####################");
        Car c = new Car(10, 20);      //Vehicle as well as Car constructor is called.
        c.color = "Black";
        c.setMaxSpeed(100);
        c.print();
        System.out.println("#####################");
    }
}

/*
When we create derived class object parent class object is also formed.
 */

/* Output
#####################
Vehicle class constructor is called!
Vehicle color : Grey
Vehicle Speed : 100
#####################
*******************
Vehicle class constructor is called!
Car constructor is called!
false
Vehicle color : null
Vehicle Speed : 20
Car numGears : 10
Car isConvertible : false
*******************
#####################
Vehicle class constructor is called!
Car constructor is called!
Vehicle color : Black
Vehicle Speed : 100
Car numGears : 10
Car isConvertible : false
#####################
 */