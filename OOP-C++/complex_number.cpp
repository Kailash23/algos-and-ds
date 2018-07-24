#include <iostream>
using namespace std;

class ComplexNumbers {
public:
int real;
int imaginary;

ComplexNumbers(int r,int i){
	real = r;
	imaginary = i;
}

void plus(ComplexNumbers const &cn){
	this->real = this->real + cn.real;
	this->imaginary = this->imaginary + cn.imaginary;
}

void multiply(ComplexNumbers const &cn){
	this->real = (this->real * cn.real)-(this->imaginary * this->imaginary);
	this->imaginary = (this->real * cn.imaginary) + (this->imaginary * cn.real);
}
void print(){
	cout<<this->real<<"+"<<this->imaginary<<"i";
}

};

int main() {
	int real1, imaginary1, real2, imaginary2;

	cin >> real1 >> imaginary1;
	cin >> real2 >> imaginary2;

	ComplexNumbers c1(real1, imaginary1);
	ComplexNumbers c2(real2, imaginary2);

	int choice;
	cin >> choice;

	if(choice == 1) {
		c1.plus(c2);
		c1.print();
	}
	else if(choice == 2) {
		c1.multiply(c2);
		c1.print();
	}
	else {
		return 0;
	}

}
