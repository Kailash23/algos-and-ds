#include <iostream>
using namespace std;

int main(){
	int i = 65;
	char c = i;     //Implicit Typecasting
	cout << c << endl;      //A

	int *p = &i;
	char *pc = (char *)p;       //Explicit Typecasting

	cout << *p << endl;       //65
	cout << *pc << endl;        //A	( Little Endian so, A printed at *(pc+0) )
	cout << *(pc + 1) << endl;        //(blank) ie null char
	cout << *(pc + 2) << endl;        //(blank) ie null char
	cout << *(pc + 3) << endl;        //(blank) ie null char

	cout << p << endl;      //0x61ff10
	cout << pc << endl;     //A
}
