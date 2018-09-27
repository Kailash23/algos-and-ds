package complex_number;

public class ComplexNumberUse {

    public static void main(String args[]) {
        ComplexNumbers c1 = new ComplexNumbers(-6, 13);
        c1.print();

        ComplexNumbers c2 = new ComplexNumbers(1, 2);
        c2.print();

        c1.multiply(c2);
        c1.print();
        c2.print();

        c1.plus(c2);
        c1.print();
        c2.print();
    }
}

/*
-6 + i13
1 + i2
-32 + i1
1 + i2
-31 + i3
1 + i2
 */