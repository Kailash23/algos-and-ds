package com.package35;

class Base {
    public final void show() {
        System.out.println("Base show");
    }
}
class Derived extends Base {
    public void show() {
        System.out.println("Derived show");
    }
}
public class Solution {
    public static void main(String[] args) {
        Base b = new Derived();
        b.show();
    }
}

/*
    Compilation Error : show() in Derived cannot override show() in Base
    public void show() {
                ^
    overridden method is final
*/
