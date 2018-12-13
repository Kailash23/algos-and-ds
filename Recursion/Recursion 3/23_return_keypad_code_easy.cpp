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
	if(num == 0 || num == 1) {
		output[0] = "";
		return 1;
	}
	int smallOutput = keypad(num / 10, output);
	int lastDigit = num % 10;
	int optionsSize  = code[lastDigit].size();

	for(int i = 0; i < (optionsSize  - 1) * smallOutput; i++) {    // making copies
		output[smallOutput + i] = output[i % smallOutput];
	}

	for(int i = 0; i < optionsSize; i++) {     // appending code
		for(int j = 0; j < smallOutput; j++) {
			output[i * smallOutput + j] += code[lastDigit][i];
		}
	}
	return smallOutput * optionsSize;
}


int main(){
	int number = 23;
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

/*
   ad
   bd
   cd
   ae
   be
   ce
   af
   bf
   cf
 */
