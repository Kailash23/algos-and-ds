package com.output43;

interface ParentA {
    // default method
    default void show() {
        System.out.println("Default ParentA");
    }
}

interface ParentB {
    // Default method
    default void show() {
        System.out.println("Default ParentB");
    }
}

// Implementation class code
class TestClass implements ParentA, ParentB {
    // Overriding default show method
    public void show() {
        // use super keyword to call the show
        // method of ParentA interface
        ParentA.super.show();

        // use super keyword to call the show
        // method of ParentB interface
        ParentB.super.show();
    }

    public static void main(String args[]) {
        TestClass d = new TestClass();
        d.show();
    }
}

/*
   Default ParentA
   Default ParentB
 */
