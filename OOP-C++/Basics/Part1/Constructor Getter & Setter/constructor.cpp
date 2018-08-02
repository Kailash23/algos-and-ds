#include <iostream>
using namespace std;
#include "teacher_class.cpp"

int main(){
	Teacher t1;		//Constructor 1 called
	Teacher t2(110);		//Constructor 2 called
	Teacher t3(30, 40);		//Constructor 3 called
	Teacher t4(t3);		//Copy constructor
	t1 = t2;		//Copy assignment operator
	Teacher t5 = t4;		//Copy constructor
}
