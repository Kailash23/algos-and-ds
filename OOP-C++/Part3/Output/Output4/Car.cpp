class Car : public Vehicle {

  public:
    int numGears;

    Car() {
        cout << "Car's default constructor " << endl;
    }

    ~Car() {
        cout << "Car's destructor " << endl;
    }
};
