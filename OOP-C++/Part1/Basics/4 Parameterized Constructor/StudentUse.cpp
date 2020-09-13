#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Parameterized Constructor
 */

int main() {
    Student s1(10, 1001);
    cout << "Address of s1 : " << &s1 << endl;

    Student s2(1002);
    s2.setAge(23, 123);
    s2.display();
}

/*
   this : 0x61ff18
   Parameterized constructor 2 called !
   Address of s1 : 0x61ff18
   Parameterized constructor 1 called !
   23 1002
 */
