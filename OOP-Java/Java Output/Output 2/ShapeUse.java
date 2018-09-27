// Class Shape and ShapeUse are in same package

class Shape{
    private int height;     // <-
    private int width;
}

public class ShapeUse {
    public static void main(String[] args) {
        Shape s = new Shape();
        System.out.println(s.height);
    }
}

/*
   height has private access in Shape
       System.out.println(s.height);
                           ^
   As height is a private data member of class Shape, thus it can’t be accessed
   outside the class.
 */
