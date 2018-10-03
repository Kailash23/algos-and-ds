#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Deep Copy
 */

int main(){
	char name[] = "finn";
	Student s1(20, name);
	s1.display();

	name[0] = 'b';
	Student s2(24, name);
	s2.display();

	s1.display();
}

/*
   finn 20
   binn 24
   finn 20
 */
