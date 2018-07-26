package fraction;

public class FractionUse {

    public static void main(String args[]) {
        Fraction f1 = new Fraction(20, 30);
        f1.print();     // 2/3

        f1.setNumerator(12);

        int d = f1.getDenominator();
        System.out.println(d);      // 1
        f1.print();     // 4

        f1.setNumerator(10);
        f1.setDenominator(30);
        f1.print();     // 1/3

        Fraction f2 = new Fraction(3, 4);
        f1.add(f2);
        f1.print();     // 13/12
        f2.print();     // 3/4

        Fraction f3 = new Fraction(4, 5);
        f3.multiply(f2);
        f3.print();     // 3/5
        f2.print();     // 3/4

        Fraction f4 = Fraction.add(f1, f3);
        f1.print();     // 13/12
        f3.print();     // 3/5
        f4.print();     // 101/60

        Fraction f5 = new Fraction(2, 1);
        f5.print();     //2
        f5.setDenominator(0);       // Denominator can't be zero

    }
}

/*
2/3
1
4
1/3
13/12
3/4
3/5
3/4
13/12
3/5
101/60
2
Denominator can't be zero
 */