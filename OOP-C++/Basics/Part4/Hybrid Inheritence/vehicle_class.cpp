class Vehicle {
	private:
	int maxSpeed;

	protected:
	int numTyres;

	public:
	string color;

	Vehicle() {
		cout << "Vehicle's default constructor " << endl;
	}

	~Vehicle() {
		cout << "Vehicle's destructor " << endl;
	}

	void print() {
		cout << "Vehicle" << endl;
	}
};
