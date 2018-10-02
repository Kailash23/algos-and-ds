class Student {

public :
    int rollNumber;

private :
    int age;

public :
    // Default constructor
    /*
		Student() {
	    	cout << "Default constructor called ! "<< endl;
	    }
	*/

    // Parameterized constructor
    Student(int rollNumber) {
        cout << "Parameterized constructor 1 called !" << endl;
        this -> rollNumber = rollNumber;
    }

    Student(int a, int r) {
        cout << "this : " << this << endl;
        cout <<"Parameterized constructor 2 called !" << endl;
        this -> age = a;
        this -> rollNumber = r;
    }

    void display() {
        cout << age << " " << rollNumber << endl;
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
