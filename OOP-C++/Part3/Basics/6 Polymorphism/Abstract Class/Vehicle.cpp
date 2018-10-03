class Vehicle {

	public:
		string color;

		virtual void print() = 0;	// Pure Virtual Function
};

/*
   Any class having pure virtual function is called abstract class.
   Abstract means incomplete.
   We can't create object of abstract class.
 */

/*
   If any class inherit abstract class :
    1. Implement all the pure virtual functions.
    2. Become an abstract class.
 */

/*
   Pure virtual function is used when we want to enforce our child class to overide
   its function.
 */
