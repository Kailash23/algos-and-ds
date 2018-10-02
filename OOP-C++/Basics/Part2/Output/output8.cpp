#include <iostream>
using namespace std;

class Student {
public :
    char name;
    int rollNo;

    Student(int num) {
        rollNo = num;
    }

    void print() {
        cout << name << " "  <<  rollNo;
    }
};

int main() {
    Student *s = new Student();
    s -> name = 'A';
    s -> rollNo = 15;
    s -> print();
}

/*
   There is Compilation error - “constructor Student() is undefined” because the
   default constructor is available only till the point we don’t create our own constructor. So Student class has only one constructor which require roll
   number as argument, hence we should pass integer as argument while creating
   any Student object.
 */
