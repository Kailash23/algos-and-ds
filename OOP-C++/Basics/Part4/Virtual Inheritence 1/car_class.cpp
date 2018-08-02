class Car : virtual public Vehicle {
	public:
	int numGears;

	Car() {
		cout << "Car's default constructor " << endl;
	}

	~Car() {
		cout << "Car's distructor " << endl;
	}

	void print() {
		cout<<"Car"<<endl;
	}
};
