class Student {

	public:
		int empId;

	private:
		int age;

	public:
		~Student() {
			cout << "Destructor called ! " << endl;
		}

		Student() {
			cout << "Constructor 1 called ! "<< endl;
		}

		// Parameterized constructor
		Student(int empId) {
			cout << "Constructor 2 called !" << endl;
			this->empId = empId;
		}

		Student(int a, int e) {
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
