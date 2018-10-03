#include <iostream>
using namespace std;

class Student {
public :
    int age;
    const int rollNumber;
};

int main() {
    Student s1;
    s1.age = 20;
    s1.rollNumber = 101;
}

/*
   There is Compilation error - error: uninitialized const member in 'class Student'
 */
