#include <iostream>
using namespace std;
#include "vehicle_class.cpp"

int main(){
	Vehicle const v1(100,20);
	//cout<<v1.getSpeed()<<endl;		// Compiler don't allow call from constant objects
	//cout<<v1.getRegId()<<endl;		// You can only constant function through constant objects
}
