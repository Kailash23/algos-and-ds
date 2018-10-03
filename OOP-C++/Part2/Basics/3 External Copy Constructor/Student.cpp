#include <string.h>
class Student {
		int age;
	public:
		char *name;

		Student(int age, char *name){
			this->age = age;
			this->name = new char[strlen(name)+1];          // Deep copy
			strcpy(this->name, name);
		}

		// Copy constructor
		Student(Student const &s){		// If we use (Student s) in place of (Student const &s)
										// it will cause infinite loop as it use copy constructor.
										// By making it reference object (&) we are avoiding use of copy constructor.
										// Use of const ensures that we can't manipulate 's' (s - constant reference of object)
			this->age = s.age;
			//this->name = s.name;		//shallow copy

			this->name = new char[strlen(s.name) + 1];
			strcpy(this->name, s.name);
		}

		void display(){
			cout << name << " " << age << endl;
		}
};


/*
   int i = 5;
   int const &j = i;		// j is the reference variable of i.
   i++;
   j++;		// we can't change the value of j as we declared it as constant.
   			// we can only access value of i using j, we can't change it using j.
 */
