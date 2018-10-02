#include <iostream>
using namespace std;

#include "Student.cpp"

/*
   Default Constructor
 */

int main() {
	// Create objects statically
	Student s1;

	s1.setAge(24, 123);      //setter
	s1.rollNumber = 101;

	cout << "Fetching age : " << s1.getAge() << endl;     //getter
	cout << "Fetching roll no : " << s1.rollNumber << endl;

	s1.display();

	cout << endl;

	// Create objects dynamically
	Student *s2 = new Student;
	(*s2).setAge(23, 123);
	(*s2).rollNumber = 104;

	cout << "Fetching age : " << s2->getAge() << endl;
	cout << "Fetching roll no : " << s2->rollNumber << endl;

	(*s2).display();
}

/*
   Constructor called !
   Fetching age : 24
   Fetching roll no : 101
   Age of student: 24
   Roll no: 101

   Constructor called !
   Fetching age : 23
   Fetching roll no : 104
   Age of student: 23
   Roll no: 104
 */
