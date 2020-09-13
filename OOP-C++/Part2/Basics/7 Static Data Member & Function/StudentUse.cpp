#include <iostream>
using namespace std;

#include "Student.cpp"

int main() {
    Student s1;
    Student s2;
    Student s3, s4, s5;

    cout << Student ::getTotalStudent() << endl;
    cout << s1.getTotalStudent() << endl;

    // cout << Student:: totalStudents << endl;		// will get error as totalStudents is private.
}

/*
   5
 */
