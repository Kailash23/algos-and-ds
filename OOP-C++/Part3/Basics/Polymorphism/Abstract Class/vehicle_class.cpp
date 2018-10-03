class Vehicle {
	public:
	string color;
	//Pure Virtual Function
	virtual void print() = 0;
};

// Any class having pure virtual function is called abstract class.

// Abstract means incomplete

// We can't create object of abstract class

/*If any class inherit abstract class :
    1. Implement all the pure virtual function.
    2. Become and abstract class.
 */

 // pure virtual function is used when we want to enforce our  child class to overide its function.
