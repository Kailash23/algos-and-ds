#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Getters & Setters
 */

int main() {
    Student s1;

    Student *s2 = new Student();

    s1.rollNumber = 12;
    s2->rollNumber = 13;

    s1.setAge(20, 123);
    s2 -> setAge(24, 123);

    s1.display();
    s2 -> display();
}

/*
   20 12
   24 13
 */

/*
   A public member of a class can be accessed outside the class.
   A private member of a class cannot be accessed outside the same class.
 */
