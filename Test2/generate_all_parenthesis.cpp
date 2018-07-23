/*
   Generate all parenthesis

   Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses.
   That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.
 */
 
#include <iostream>
using namespace std;

void printWellFormedParanthesisHelper( int open, int close, string output){
	if(open == 0 && close == 0) {
		cout<<output<<endl;
		return;
	}
	if(open) {
		printWellFormedParanthesisHelper(open-1,close,output+"(");
	}
	if(open<close) {
		printWellFormedParanthesisHelper(open,close-1,output+")");
	}
}

void printWellFormedParanthesis(int n){
	string output = "";
	int open = n;
	int close = n;
	printWellFormedParanthesisHelper(open,close,output);
}

int main(){
	int s = 2;
	printWellFormedParanthesis(s);
}
