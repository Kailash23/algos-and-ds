
package com.output8;

class Book{
    int price;
    static int count;

    public Book(int price) {
        this.price = price;
        count++;
    }
}

public class MCQs {
    public static void main(String[] args) {
        System.out.print(Book.count + " ");
        Book b1 = new Book(500);
        Book b2 = new Book(600);
        System.out.println(Book.count);
    }
}

/*
   0 2
 */

/*
   More about static keyword:
   static keyword is bound to the class and not to an individual object, thus we
   can’t make constructors static.
 */
