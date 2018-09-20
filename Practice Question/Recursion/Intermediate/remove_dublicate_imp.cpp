/*
   Remove Duplicates Recursively

   Given a string S, remove consecutive duplicates from it recursively.
 */

#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	if(strlen(input) <= 1) {
		return;
	}
	if(input[0] == input[1]) {
		int i = 1;
		for(; i < strlen(input); i++) {
			input[i - 1] = input[i];
		}
		input[i - 1] = '\0';
		removeConsecutiveDuplicates(input);
	} else {
		removeConsecutiveDuplicates(input + 1);
	}
}

int main(){
	char str[] = "aabccba";
	removeConsecutiveDuplicates(str);
	cout << str << endl;
}

/*
   abcba
 */
