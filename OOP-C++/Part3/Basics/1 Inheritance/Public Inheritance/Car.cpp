class Car : public Vehicle {

  public:
    int numGears;

    void print() {
        cout << "NumTyres : " << numTyres << endl; // Can access protected property as it is sub-class of Vehicle.
        cout << "Color : " << color << endl;       // Can access public property of Vehicle
        cout << "Num gears : " << numGears << endl;
        //cout<<"Max Speed : " << maxSpeed<<endl;		//maxSpeed is private member of Vehicle
    }
};

/*
   If we didn't specify access modifier while inheriting by default access modifier
   is private.
 */
