package com.output_programs;

public class Exception extends Throwable {
    public static void main(String[] args){

        try{
            int a = 5/0;
        }
//        catch(Exception e){     //Will give compile time error
//            System.out.print("Exception caught ");
//        }
        catch(ArithmeticException e){
            System.out.print("Arithmetic Exception caught ");
        }
        finally{
            System.out.print("finally block");
        }
    }
}
/*
Error: Error:(9, 15) java: incompatible types: output_programs.
Exception cannot be converted to java.lang.Throwable
*/
/*
Arithematic Exception can't be caught after Exception
*/
