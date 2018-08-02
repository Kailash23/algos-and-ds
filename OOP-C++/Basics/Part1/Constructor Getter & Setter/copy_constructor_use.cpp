#include <iostream>
using namespace std;
#include "teacher_class.cpp"

int main() {

	Teacher t1(10, 1001);
	cout<<"T1:- ";
	t1.display();

	Teacher t2(t1);     //Copy constructor is called. (static- static)
	cout<<"T2:- ";
	t2.display();

	cout<<"************************************"<<endl;

	Teacher *t3 = new Teacher(20, 2003);
	cout<< "T3:- ";
	t3->display();

	Teacher t4(*t3);        //static - dynamic

	Teacher *t5 = new Teacher(*t3);     //dynamic - dynamic

	Teacher *t6 = new Teacher(t1);      //dynamic - static

	cout<<"************************************"<<endl;
	Teacher t7;
}

/*
   Constructor 3 called !
   T1:- Age:- 10 empId:- 1001
   T2:- Age:- 10 empId:- 1001
   ************************************
   Constructor 3 called !
   T3:- Age:- 20 empId:- 2003
   ************************************
   Constructor 1 called !
   Destructor called !
   Destructor called !
   Destructor called !
   Destructor called !
 */
