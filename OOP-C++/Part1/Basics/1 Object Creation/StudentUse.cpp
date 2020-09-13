#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Object Creation
 */

int main() {
    // Creating objects statically
    Student s1;
    Student s3, s4, s5;

    s1.age = 23;
    s1.rollNumber = 100;

    cout << s1.age << endl;
    cout << s1.rollNumber << endl;

    // Creating objects dynamically
    Student *s6 = new Student; // Or Student *s6 = new Student();
    (*s6).age = 23;
    (*s6).rollNumber = 104;

    // Above statements can be written as below.
    s6->age = 23;
    s6->rollNumber = 104;

    cout << s6->age << endl;
    cout << s6->rollNumber << endl;
}

/*
   23
   100
   23
   104
 */

/*
   A public member of a class can be accessed outside the class.
   A private member of a class cannot be accessed outside the same class.
 */
