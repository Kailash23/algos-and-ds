package classes_and_objects_basics;

public class Student {
    private int rollNumber;     //All the property is initialised with 0
    String name;        //String store address so it store null

    public Student(String n, int rollno) {
        name = n;
        rollNumber = rollno;
    }

//    public Student(){     //can't do this with custom constructor
//        rollNumber = 10;
//    }

    public Student(String n) {
        name = n;
    }

    public void setRollNumber(int rn) {
        if (rn <= 0) {
            return;
        }
        rollNumber = rn;
    }

    public int getRollNumber() {
        return rollNumber;
    }

    public void print() {
        System.out.println(name + " " + rollNumber);
    }
}

/*
   (Access modifier)
   Default- Within package
   Public - Anywhere
   Private - Only within class
 */

 /*
    Specifier	class	subclass	package     world
    private      yes	   no	      no	     no
    protected	 yes	   yes	      yes        no
    public	     yes	   yes	      yes	     yes
    (none)       yes       no	      yes	     no
  */
