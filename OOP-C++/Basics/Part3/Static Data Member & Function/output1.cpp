#include <iostream>
using namespace std;

class Student {
	public:

	int rollNumber;

	static int getRollNumber() {
		return rollNumber;
	}
};


int main() {
	Student s;
	s.rollNumber = 101;
	cout << s.getRollNumber() << endl;
}

/*
   error: invalid use of member 'Student::rollNumber' in static member function
   return rollNumber;
 */
