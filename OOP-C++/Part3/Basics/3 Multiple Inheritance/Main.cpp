#include <iostream>
using namespace std;

#include "Student.cpp"
#include "TA.cpp"
#include "Teacher.cpp"

/*
   Multiple Inheritance
 */

int main() {
    TA a;
    a.Student ::print();
    a.Teacher ::print();
    a.print();

    a.Teacher ::name = "abcd";
    //a.name = "abcd";  // Will cause ambiguity.
}

/*
   Student
   Teacher
   TA
 */
