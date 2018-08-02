class Teacher {

	public:
	int empId;

	private:
	int age;

	public:
	~Teacher() {
		cout << "Destructor called ! " << endl;
	}

	Teacher() {
		cout << "Constructor 1 called ! "<< endl;
	}

	// Parameterized constructor
	Teacher(int empId) {
		cout << "Constructor 2 called !" << endl;
		this->empId = empId;
	}

	Teacher(int a, int e) {
		cout << "Constructor 3 called ! " << endl;
		this->age = a;
		this->empId = e;
	}

	void display() {
		cout <<"Age:- " <<age << " " <<"empId:- " <<empId << endl;
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
