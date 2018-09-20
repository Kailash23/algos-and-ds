/*
   Replace Character Recursively

   Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
   Do this recursively.
 */
#include <iostream>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
	if(input[0] == '\0') {
		return;
	}
	if(input[0] == c1) {
		input[0] = c2;
	}
	replaceCharacter(input + 1, c1, c2);
}

int main(){
	char str[] = "abacde";
	char c1 = 'a';
	char c2 = 'x';
	replaceCharacter(str, c1, c2);
	cout << str;
}
