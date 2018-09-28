package com.complex_number;

public class ComplexNumbers {

    int real;
    int imaginary;

    ComplexNumbers(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    void plus(ComplexNumbers c2) {
        this.real = this.real + c2.real;
        this.imaginary = this.imaginary + c2.imaginary;
    }

    void multiply(ComplexNumbers c2) {
        int real = (this.real * c2.real) - (this.imaginary * c2.imaginary);
        int imaginary = (this.real * c2.imaginary) + (this.imaginary * c2.real);
        this.real = real;
        this.imaginary = imaginary;
    }

    void print() {
        System.out.println(this.real + " + i" + this.imaginary);
    }

}
