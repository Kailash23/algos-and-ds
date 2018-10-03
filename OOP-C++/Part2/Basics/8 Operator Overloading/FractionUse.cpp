#include <iostream>
using namespace std;

#include "Fraction.cpp"

int main() {
	Fraction f1(10, 2);
	Fraction f2(15, 4);

	Fraction f3 = f1.add(f2);
	Fraction f4 = f1 + f2;
	f1.print();
	f2.print();
	f3.print();
	f4.print();

	Fraction f5 = f1 * f2;
	f5.print();

	if(f1 == f2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal " << endl;
	}

	cout << endl;

	Fraction f6(10, 2);
	Fraction f7(15, 4);

	f6.print();
	Fraction f8 = ++(++f1);
	f7.print();
	f8.print();

	cout << endl;

	Fraction f11(2, 3);
	Fraction f12 = f11++;
	f11.print();
	f12.print();

	cout << endl;

	int i = 5, j = 3;
	(i += j) += j;

	cout << i << " " << j << endl;

	Fraction f9(10, 3);
	Fraction f10(5, 2);

	(f1 += f2) += f2;

	f1.print();
	f2.print();
}

/*
   10 / 2
   15 / 4
   35 / 4
   35 / 4
   75 / 4
   Not equal

   10 / 2
   15 / 4
   7 / 1

   5 / 3
   2 / 3

   11 3
   29 / 2
   15 / 4
 */
