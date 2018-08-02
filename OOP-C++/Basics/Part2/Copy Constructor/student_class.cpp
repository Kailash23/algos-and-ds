#include <string.h>
class Student {
	int age;
	public:
	char *name;

	public:
	Student(int age, char *name){
		this->age = age;
		// this->name = name;          //shallow copy

		this->name = new char[strlen(name)+1];          //deep copy
		strcpy(this->name, name);
	}

	Student(Student const &s){		//This will cause infinite loop. (Student s) will use copy constructor.
		this->age = s.age;
		//this->name = s.name;		//shallow copy

		this->name = new char[strlen(s.name)+1];
		strcpy(this->name, s.name);
	}

	void display(){
		cout<<name<<" "<<age<<endl;
	}
};
