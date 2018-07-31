/*
   Copy constructor and copy assignment operator has same work (to make a copy of object),
   the only difference is copy constructor create copy at the time of object creation of
   object. While copy assignment operator work when both the objects were in memory.
 */

#include <iostream>
using namespace std;
#include "Teacher.cpp"

int main(){
	Teacher t1(10, 505);
	Teacher t2;

	Teacher *t3 = new Teacher(30);
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
