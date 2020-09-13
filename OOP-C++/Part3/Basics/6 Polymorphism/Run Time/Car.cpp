class Car : public Vehicle {

  public:
    int numGears;

    void print() { //If car class doen't have print then v2 will called
        cout << "Car" << endl;
    }
};
