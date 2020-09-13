class Vehicle {
  public:
    int speed;
    const int regId;
    int &x;

    Vehicle(int r, int sp) : regId(r), speed(sp), x(this->speed) {
    }

    int getSpeed() {
        return speed;
    }

    int getRegId() {
        return regId;
    }
};
