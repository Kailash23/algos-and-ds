/*
   Given an integer n, using phone keypad find out and print all the possible
   strings that can be made using digits of input n.
 */

#include <iostream>
using namespace std;

string code[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKeypadHelper(int num, string output){
	if(num == 0) {
		cout << output << endl;
		return;
	}
	int appendNum = num % 10;
	for(int i = 0; i < code[appendNum].size(); i++) {
		printKeypadHelper(num / 10, code[appendNum][i] + output);
	}
}

void printKeypad(int num){
	string output;
	printKeypadHelper(num, output);
}


int main(){
	int number = 23;
	printKeypad(number);
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
