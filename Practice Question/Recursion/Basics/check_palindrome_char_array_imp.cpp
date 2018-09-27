/*
   Check Palindrome (recursive)

   Check if a given String S is palindrome or not (using recursion). Return true
   or false.
 */

#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char input[]) {
	if (strlen(input) == 0){
		return true;
	}
	if (input[0] != input[strlen(input) - 1]){
		return false;
	}
	input[strlen(input) - 1] = '\0';
	return checkPalindrome(input + 1);
}

int main(){
	char str[] = "abccba";
	if(checkPalindrome(str)){
		cout << "Palindrome" << endl;
	} else {
		cout << "Not Palindrome" << endl;
	}
}

/*
	Palindrome
 */

 /*
 bool checkPalindrome(char input[]) {
 	if(strlen(input) <= 1){
 		return true;
 	}
 	bool smallAns;
 	if(input[0] == input[strlen(input) - 1]){
 		smallAns = true;
 	} else {
 		smallAns = false;
 	}
 	char *temp = new char[100];
 	int ind = 0;
 	for(int i = 1; i < strlen(input) - 1; i++){
 	    temp[ind++] = input[i];
 	}
 	temp[ind] = '\0';
 	return smallAns && checkPalindrome(temp);
 }
 */
