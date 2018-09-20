/*
   Print Keypad Combinations Code

   Given an integer n, using phone keypad find out and print all the possible
   strings that can be made using digits of input n.
   Note : The order of strings are not important. Just print different strings
   in new lines.
 */

#include <iostream>
#include <string>
using namespace std;

string getString(int d){
	if(d == 2) {
		return "abc";
	}
	if(d == 3) {
		return "def";
	}
	if(d == 4) {
		return "ghi";
	}
	if(d == 5) {
		return "jkl";
	}
	if(d == 6) {
		return "mno";
	}
	if(d == 7) {
		return "pqrs";
	}
	if(d == 8) {
		return "tuv";
	}
	if(d ==9) {
		return "wxyz";
	}
	return " ";
}

void keypad(int num, string output){
	if(num == 0) {
		cout << output << endl;
		return;
	}

	int lastDigit = num % 10;
	int smallOutput = num / 10;
	string option = getString(lastDigit);

	for(int i = 0; i < option.size(); i++) {
		keypad(smallOutput, option[i] + output);
	}
}

void printKeypad(int num){
	string output = "";
	keypad(num, output);
}

int main(){
	int number = 234;
	printKeypad(number);
}
