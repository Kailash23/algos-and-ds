#include <iostream>
using namespace std;

class Student {
  public:
    const int rollNumber; // Or - int const rollNumber;
    int age;

    int &x; //Error: should be initialized

    Student(int r, int a) : rollNumber(r), age(a) {
    }
};

int main() {
    Student s1(100, 23);
    s1.x = age;
    cout << s1.rollNumber << " " << s1.age << " " << s1.x;
}

/*
    Correction:-
    	Student(int r, int a): rollNumber(r) ,age(a), x(this -> age){

    	}
*/
