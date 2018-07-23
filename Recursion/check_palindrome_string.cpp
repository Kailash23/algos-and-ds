/*
   Check Palindrome (recursive)
   Check if a given String S is palindrome or not (using recursion). Return true or false.
 */

#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string str) {

	if(str.length() <= 1) {
		return true;
	}

	if(str[0] == str[str.length()-1]) {
		return checkPalindrome(str.substr(1,str.length()-2));
	} else {
		return false;
	}

}

int main(){
	string input = "qwerrewq";
	bool answer = checkPalindrome(input);
	if(answer) {
		cout<<"Palindrome";
	} else {
		cout<<"Not Palindrome";
	}
}
