class Student {
	public:
		int age;
		int const rollNumber;
		int &x;

		Student(int r, int a): rollNumber(r) ,age(a), x(this -> age){

		}
};
