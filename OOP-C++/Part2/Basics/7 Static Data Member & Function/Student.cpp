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
			return totalStudents;		// we can't use non static data member or non static function.
		}
};

int Student :: totalStudents = 0;	//Initialize static data memeber

/*
   Static funtion doesn't have this pointer.
 */
