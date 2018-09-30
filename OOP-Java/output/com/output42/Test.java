package com.output42;

class Parent1 {
    void fun() {
        System.out.println("Parent1");
    }
}

class Parent2 {
    void fun() {
        System.out.println("Parent2");
    }
}

// Error : Test is inheriting from multiple classes
class Test extends Parent1, Parent2 {
    public static void main(String args[]) {
        Test t = new Test();
        t.fun();
    }
}

/*
    Compilation Error: multiple inheritence is not supported in java.
    class Test extends Parent1, Parent2 {
                              ^
 */
