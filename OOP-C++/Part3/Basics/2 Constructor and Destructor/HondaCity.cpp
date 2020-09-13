class HondaCity : public Car {

  public:
    HondaCity(int x, int y) : Car(x, y) {
        cout << "Honda city's constructor" << endl;
    }

    ~HondaCity() {
        cout << "Honda city's destructor" << endl;
    }
};
