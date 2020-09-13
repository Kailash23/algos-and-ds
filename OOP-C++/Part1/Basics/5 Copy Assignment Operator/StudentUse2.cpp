#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Copy Constructor
 */

int main() {
    Student t1;         // Constructor 1 called
    Student t2(110);    // Constructor 2 called
    Student t3(30, 40); // Constructor 3 called
    Student t4(t3);     // Copy constructor
    t1 = t2;            // Copy assignment operator
    Student t5 = t4;    // Copy constructor (not copy assignment operator)
}

/*
   Constructor 1 called !
   Constructor 2 called !
   Constructor 3 called !
   Destructor called !
   Destructor called !
   Destructor called !
   Destructor called !
   Destructor called !
 */

/*
   Destructor :-
   1. It is invoked when object goes out of the scope
   2. It bears same name as that of the class and precedes tilde sign.
   3. It can be declared in private section
 */
