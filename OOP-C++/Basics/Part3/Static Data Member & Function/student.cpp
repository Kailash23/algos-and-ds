class Student {
	static int totalStudents;

public:
	int rollNumber;
	int age;

	Student(){
		totalStudents++;
	}

	int getRollNumber(){
		return rollNumber;
	}

	static int getTotalStudent(){
		return totalStudents;		//we cant use non static data member or non static function.

		//Static funtion doesn't have this pointer
	}
};

int Student :: totalStudents = 0;	//Initialize static data memeber
