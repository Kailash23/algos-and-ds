/*
   Remove Duplicates Recursively

   Given a string S, remove consecutive duplicates from it recursively.
   
   Sample Input :
   aabccba
   Sample Output :
   abcba
 */

#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	if(strlen(input) <= 1) {	// If string is 0 and 1 length we will simply return without any change.
		return;
	}
	if(input[0] == input[1]) {
		for(int i = 1; i <= strlen(input); i++) {
			input[i - 1] = input[i];
		}
		removeConsecutiveDuplicates(input);
	} else {
		removeConsecutiveDuplicates(input + 1);
	}
}

int main(){
	char str[] = "aaaabbbddd";
	removeConsecutiveDuplicates(str);
	cout << str;
}

/*
   abd
 */

/*
	void removeConsecutiveDuplicates(char *input) {
		if(strlen(input) <= 1) {	// If string is 0 and 1 length we will simply return without any change.
			return;
		}
		if(input[0] == input[1]) {		//imp
			int i = 1;
			for(; input[i] != '\0'; i++) {
				input[i - 1] = input[i];
			}
			input[i - 1] = '\0';
			removeConsecutiveDuplicates(input);
		} else {
			removeConsecutiveDuplicates(input + 1);
		}
	}
*/
