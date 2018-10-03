class Vehicle {

	private:
		int maxSpeed;

	protected:
		int numTyres;

	public:
		string color;

	/*
		Vehicle() {
			cout << "Vehicle's default constructor";
		}
	*/

	Vehicle(int z) {
		cout << "Vehicle's parameterized constructor" << endl;
		maxSpeed = z;
	}

	~Vehicle() {
		cout << "Vehicle's Destructor" << endl;
	}
};
