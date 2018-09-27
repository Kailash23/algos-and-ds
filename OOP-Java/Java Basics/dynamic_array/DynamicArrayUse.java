package dynamic_array;

public class DynamicArrayUse {

    public static void main(String[] args) {
        DynamicArray d = new DynamicArray();

        for (int i = 0; i < 5; i++) {
            d.add(i + 10);
        }

        System.out.println(d.size());       //100

        d.set(4, 10);
        System.out.println(d.get(3));       //13
        System.out.println(d.get(4));       //10

        while (!d.isEmpty()) {
            System.out.println(d.removeLast());
            System.out.println("size = " + d.size());
        }
    }
}

/*
5
13
10
10
size = 4
13
size = 3
12
size = 2
11
size = 1
10
size = 0
 */