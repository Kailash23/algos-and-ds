
package com.output11;

class Vehicle{
    private Vehicle(){
        System.out.println("constructor of Vehicle");
    }
}

class Car {
    public static void main(String[] args) {
        Vehicle v = new Vehicle();
    }
}

/*
   Compile time error : private constructor
   Vehicle() has private access in Vehicle
        Vehicle v = new Vehicle();
                    ^
 */
