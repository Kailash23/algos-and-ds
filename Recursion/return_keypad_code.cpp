/*
   Return Keypad Code

   Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
   Return empty string for numbers 0 and 1.
   Note : The order of strings are not important.
   Input Format :
 */

#include <iostream>
#include <string>
using namespace std;

string code[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
	if(num == 0|| num == 1) {
		output[0] = "";
		return 1;
	}
	int smallOutput = keypad(num / 10, output);
	int appendNumber = num % 10;
	int numChar = code[appendNumber].size();

	for(int i = 0; i < (numChar - 1) * smallOutput; i++) {
		output[smallOutput + i] = output[i % smallOutput];
	}
	for(int i = 0; i < numChar; i++) {
		for(int j = 0; j < smallOutput; j++) {
			output[i * smallOutput + j] += code[appendNumber][i];
		}
	}
	return smallOutput * numChar;

}


int main(){
	int number = 234;
	int n = number;
	int size = 1;
	while(n != 0) {
		int num = n % 10;
		size = size * code[num].size();
		n = n / 10;
	}
	string *output = new string[size];
	int count = keypad(number, output);
	for(int i = 0; i < count; i++ ) {
		cout << output[i] << endl;
	}
}
