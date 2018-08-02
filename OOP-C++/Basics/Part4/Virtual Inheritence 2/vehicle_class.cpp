class Vehicle {
	private:
	int maxSpeed;

	protected:
	int numTyres;

	public:
	string color;

	// Vehicle() {
	// 	cout << "Vehicle's default constructor " << endl;
	// }

	~Vehicle() {
		cout << "Vehicle's destructor " << endl;
	}

	Vehicle(int z) {
		cout<<"Vehicle's parameterized constructor :"<<z<<endl;
	}

	void print() {
		cout << "Vehicle" << endl;
	}
};
