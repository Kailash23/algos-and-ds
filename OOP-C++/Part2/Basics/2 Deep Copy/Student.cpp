#include <cstring>

class Student {
    int age;
    char *name;

  public:
    Student(int age, char *name) {
        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display() {
        cout << name << " " << age << endl;
    }
};
