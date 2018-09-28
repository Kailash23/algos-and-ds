package com.output12.p2;

import com.output12.p1.Vehicle;

class Bike {
    void props() {
        Vehicle v = new Vehicle();
        v.name = "Pulsar";
        System.out.println(v.name);
    }

    public static void main(String args[]){
        Bike b = new Bike();
        b.props();
    }
}

/*
    Compilation Error : name has protected access in Vehicle
    v.name = "Pulsar";
      ^

     System.out.println(v.name);
                      ^
  */

/*

   Specifier	class	subclass	package     world

   protected	yes	      yes	      yes        no

    A. protected variable can be accessed withing classes under same package
    B. Car is the subclass of Vehicle ie can be accessed in subclass.
    C. name is used in Car class which is from different package ie Outside world


   Therefore answer is C.
 */

/*
   keyword protected - allow us to use datamember of a class A outside the package but only in classes which inherit form A.
 */
