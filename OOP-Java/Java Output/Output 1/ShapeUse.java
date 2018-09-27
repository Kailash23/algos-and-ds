// Class Shape and ShapeUse are in same package

class Shape{
    int height;
    int width;
}

class ShapeUse {
    public static void main(String[] args) {
        Shape s = new Shape();
        s.height = 1;
        System.out.println(s.height);
    }
}

/*
   1
   Since height is a default data member of class Shape and Shape and ShapeUse both
   the classes are in same package. So we can access height via shape object in
   ShapeUse class.
 */

/*
   Specifier	class	subclass	package     world
   private      yes	      no	      no	     no
   protected	yes	      yes	      yes        no
   public	    yes	      yes	      yes	     yes
   (none)       yes       no	      yes	     no
 */
