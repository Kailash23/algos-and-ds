class Truck :  public Vehicle {

	public:
		Truck() {
			cout << "Truck's constructor " << endl;
		}

		~Truck() {
			cout << "Truck's destructor " << endl;
		}

		void print() {
			cout << "Truck" << endl;
		}
};
