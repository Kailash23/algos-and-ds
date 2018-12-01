#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int sum = 0;
	string expr = "1234";
	for(int i = 0; i < expr.length(); i++) {
		sum += expr[i] - '0';     //Subtracting '0' this will (convert from char to int in c++)
		cout << "Dig: " << expr[i] - '0' << endl;
	}
	cout << "Sum:" << sum << endl << endl;

	int sum1 =0;
	char expr1[] = "1234";
	for(int i = 0; i < strlen(expr1); i++) {
		sum1 += expr1[i] - '0';     //Subtracting '0' this will (convert from char to int in c++)
		cout << "Dig: " << expr1[i] - '0' << endl;
	}
	cout << "Sum :" << sum1 << endl;
}
