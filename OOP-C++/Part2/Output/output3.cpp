#include <iostream>
using namespace std;

class Student {
public:
	const int rollNumber;
	int age;

	Student(int r, int a) : rollNumber(r), age(a) {

	}
};


int main() {
	Student s1(100, 23);
	cout << s1.rollNumber << " " << s1.age;
}

/*
   100 23
 */
