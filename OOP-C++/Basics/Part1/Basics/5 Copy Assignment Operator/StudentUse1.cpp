#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Copy Constructor
 */

int main() {

	Student t1(10, 1001);		// Constructor 3 called ! , Destructor called !
	cout << "T1:- ";
	t1.display();

	Student t2(t1);     // Copy constructor is called. (static- static)  Destructor called !
	cout << "T2:- ";
	t2.display();

	cout << endl;

	Student *t3 = new Student(20, 2003);		//   Constructor 3 called !
	cout << "T3:- ";
	t3->display();

	Student t4(*t3);        // (static - dynamic)   Destructor called !

	Student *t5 = new Student(*t3);     // (dynamic - dynamic)

	Student *t6 = new Student(t1);      // (dynamic - static)

	cout << endl;
	Student t7;		// Constructor 1 called ! ,  Destructor called !
}

/*
   Constructor 3 called !
   T1:- Age:- 10 empId:- 1001
   T2:- Age:- 10 empId:- 1001

   Constructor 3 called !
   T3:- Age:- 20 empId:- 2003

   Constructor 1 called !
   Destructor called !
   Destructor called !
   Destructor called !
   Destructor called !
 */
