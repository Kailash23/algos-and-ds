class Car : public Vehicle {

	public :
		int numGears;

	Car(int x, int y) : Vehicle(x) {		// Explicit call to Vehicle constructor.
		cout << "Car's parameterized constructor " << endl;
		numGears = y;
	}

	~Car() {
		cout << "Car's Destructor " << endl;
	}

	void print() {
		cout << "NumTyres : " << numTyres << endl;
		cout << "Color : " << color << endl;
		cout << "Num gears :" << numGears << endl;
	}
};


/*
	Implicit call to Vehicle default constructor look like.

	Car() : Vehicle() {
		cout << "Car's default constructor " << endl;
	}
	But if we use like this we are making explicit call to Vehicle's default constructor.
*/
