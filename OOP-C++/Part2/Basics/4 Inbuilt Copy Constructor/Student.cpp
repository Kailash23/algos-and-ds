#include <string.h>
class Student {
	
		int age;
	public:
		char *name;

		public:
		Student(int age, char *name){
			this->age = age;

			this->name = new char[strlen(name)+1];          // Deep copy
			strcpy(this->name, name);
		}

		void display(){
			cout << name << " " << age << endl;
		}
};
