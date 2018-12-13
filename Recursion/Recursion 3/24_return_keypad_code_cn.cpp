/*
   Return Keypad Code

   Given an integer n, using phone keypad find out all the possible strings that
   can be made using digits of input n.
   Return empty string for numbers 0 and 1.
   Note : The order of strings are not important.
   Input Format :
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
	if(d == 9) {
		return "wxyz";
	}
	return " ";
}

int keypad(int num, string output[]){
	if(num == 0) {
		output[0] = "";
		return 1;
	}
	int lastDigit = num % 10;
	int smallNumber = num / 10;
	int smallOutputSize = keypad(smallNumber, output);
	string options = getString(lastDigit);
	for(int i = 0; i < options.length() - 1; i++) {
		for(int j = 0; j < smallOutputSize; j++) {
			output[j + (i + 1) * smallOutputSize] = output[j];
		}
	}
	int k = 0;
	for(int i = 0; i < options.length(); i++) {
		for(int j = 0; j < smallOutputSize; j++) {
			output[k] = output[k] + options[i];
			k++;
		}
	}
	return smallOutputSize * options.length();
}

int main(){
	int number = 234;		// 2-'abc' 3-'def' 4-'ghi'
	string *output = new string[1000];
	int count = keypad(number, output);
	for(int i = 0; i < count; i++ ) {
		cout << output[i] << endl;
	}
}

/*
   adg
   bdg
   cdg
   aeg
   beg
   ceg
   afg
   bfg
   cfg
   adh
   bdh
   cdh
   aeh
   beh
   ceh
   afh
   bfh
   cfh
   adi
   bdi
   cdi
   aei
   bei
   cei
   afi
   bfi
   cfi

 */
