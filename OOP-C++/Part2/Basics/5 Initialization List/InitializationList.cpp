#include <iostream>
using namespace std;

#include "Student.cpp"
#include "Vehicle.cpp"

int main(){
	Student s1(100,20);
	Vehicle v1(26, 220);
	cout << s1.age << endl;
	cout << s1.rollNumber << endl;
	cout << v1.maxSpeed << endl;
	cout << v1.mileage << endl;
}

/*
   20
   100
   220
   26
 */
