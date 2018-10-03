#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Copy Assignment Operator
 */

int main(){
	Student t1(10, 505);
	Student t2;

	Student *t3 = new Student(30);
	t2 = t1;
	*t3 = t1;
	t2 = *t3;

	t1.display();
	t2.display();
	t3->display();
	delete t3;
}

/*
   Constructor 3 called !
   Constructor 1 called !
   Constructor 2 called !
   Age:- 10 empId:- 505
   Age:- 10 empId:- 505
   Age:- 10 empId:- 505
   Destructor called !
   Destructor called !
   Destructor called !
*/

/*
   Copy constructor and copy assignment operator has same work (to make a copy of
   object), the only difference is copy constructor create copy at the time of object
   creation of object. While copy assignment operator work when both the objects were
   in memory.
 */
