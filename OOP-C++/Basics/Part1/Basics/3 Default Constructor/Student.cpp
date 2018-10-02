class Student {

public:
	int rollNumber;

private:
	int age;

public:
	// Default constructor
	Student() {
		cout << "Constructor called ! "<< endl;
	}

	void display() {
		cout << "Age of student: " << age << endl <<"Roll no: " << rollNumber << endl;
		// cout << this.age << " " << this.rollNumber << endl;
	}

	int getAge() {
		return age;
	}

	void setAge(int a, int password) {
		if(password != 123) {
			return;
		}
		if(a < 0) {
			return;
		}
		age = a;
	}
};

/*
   By default - access specifier is private
 */
