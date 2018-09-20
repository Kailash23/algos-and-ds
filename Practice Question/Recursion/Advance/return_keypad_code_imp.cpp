/*
   Return Keypad Code

   Given an integer n, using phone keypad find out all the possible strings that
   can be made using digits of input n.
   Return empty string for numbers 0 and 1.
   Note : The order of strings are not important.
 */

#include <iostream>
#include <math.h>
using namespace std;

string code[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
	if(num == 0 || num == 1) {
		output[0] = "";
		return 1;
	}
	int smallOutputSize = keypad(num / 10, output);
	int appendNumber = num % 10;
	for(int i = 0; i < code[appendNumber].size() - 1; i++) {
		for(int j = 0; j < smallOutputSize; j++) {
			output[j + ((i + 1) * smallOutputSize)] = output[j];
		}
	}
	int k = 0;
	for(int i = 0; i <  code[appendNumber].size(); i++) {
		for(int j = 0; j < smallOutputSize; j++) {
			output[k] = output[k] + code[appendNumber][i];
			k++;
		}
	}
	return k;
}

int main(){
	int n = 123;
	int size = 1;
	int num = n;
	while(num != 0) {
		int k = num % 10;
		if((k != 1) && (k != 0)) {
			size = size * code[k].size();
		}
		num = num / 10;
	}
	string *output = new string[size];
	int count = keypad(n, output);
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
