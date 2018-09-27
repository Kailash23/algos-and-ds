class Book{
    final int price = 10;
}

public class MCQs {
    public static void main(String[] args) {
        Book b = new Book();
        b.price = 16;
        System.out.println(b.price);
    }
}

/*
   cannot assign a value to final variable price
        b.price = 16;
         ^
   price is a final field, thus statement “ b.price = 16 “ is incorrect since we
   cannot re assign a final variable
 */
