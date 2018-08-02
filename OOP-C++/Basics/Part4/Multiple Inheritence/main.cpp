#include <iostream>
using namespace std;
#include "student_class.cpp"
#include "teacher_class.cpp"
#include "technical_assistence_class.cpp"


int main() {
	TA a;

	a.Student :: print();
	a.print();
	a.Teacher :: name = "abcd";
}

/*
   Student
   TA
 */
