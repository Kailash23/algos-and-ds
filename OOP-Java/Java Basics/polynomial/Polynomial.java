package polynomial;

import dynamic_array.DynamicArray;

public class Polynomial {

    DynamicArray arr = new DynamicArray();

    Polynomial() {

    }

    Polynomial add(Polynomial second) {
        int s1 = this.arr.size();
        int s2 = second.arr.size();
        if (s2 - s1 > 0) {
            int diff = s2 - s1;
            for (int i = 0; i < diff; i++) {
                this.arr.add(0);
            }
        } else {
            int diff = s1 - s2;
            for (int i = 0; i < diff; i++) {
                second.arr.add(0);
            }
        }
        int a1 = this.arr.size();
        int a2 = second.arr.size();

        int maxSize = Math.max(a1, a2);
        for (int i = 0; i < maxSize; i++) {
            int s = this.arr.get(i) + second.arr.get(i);
            this.arr.set(i, s);
        }
        return this;
    }

    Polynomial subtract(Polynomial second) {
        int s1 = this.arr.size();
        int s2 = second.arr.size();
        if (s2 - s1 > 0) {
            int diff = s2 - s1;
            for (int i = 0; i < diff; i++) {
                this.arr.add(0);
            }
        } else {
            int diff = s1 - s2;
            for (int i = 0; i < diff; i++) {
                second.arr.add(0);
            }
        }
        int a1 = this.arr.size();
        int a2 = second.arr.size();

        int maxSize = Math.max(a1, a2);
        for (int i = 0; i < maxSize; i++) {
            int s = this.arr.get(i) - second.arr.get(i);
            this.arr.set(i, s);
        }
        return this;
    }

    Polynomial multiply(Polynomial second) {
        int s1 = this.arr.size();
        int s2 = second.arr.size();

        Polynomial result = new Polynomial();

        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                int pow = i + j;
                int res = this.arr.get(i) * second.arr.get(j);
                res = res + result.arr.get(pow);
                result.arr.set(pow, res);
            }
        }
        return result;
    }

    void setCoefficient(int degree, int coefficient) {
        for (int i = 0; i <= degree; i++) {
            if (this.arr.get(i) == 0) {
                this.arr.set(i, 0);
            }
            this.arr.set(degree, coefficient);
        }
    }

    public void print() {
        int size = this.arr.size();
        for (int i = 0; i < size; i++) {
            if (this.arr.get(i) != 0) {
                System.out.print(this.arr.get(i) + "x" + i + " ");
            }
        }
    }


}
