#include <iostream>
using namespace std;

class Student {
    int rollNumber;     // No access modifier means private - scope within class
};

int main() {
    Student s;
    cout << s.rollNumber;
}

/*
   Error : Student::rollNumber' is private within this context
 */
