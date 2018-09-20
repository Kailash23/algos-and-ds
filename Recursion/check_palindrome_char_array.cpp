/*
   Check Palindrome (recursive)
   Check if a given String S is palindrome or not (using recursion). Return true or false.
 */

#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char input[]) {
	int start = 0;
	int last = strlen(input) - 1;
	if(strlen(input) == 0) {
		return true;
	}
	bool ans;
	if(input[start] == input[last]) {
		ans =  true;
	} else {
		ans = false;
	}
	char *temp = new char[100];
	int s = 0;
	for(int i = start + 1; i < last; i++) {
		temp[s++] = input[i];
	}
	temp[s] = '\0';
	ans = ans && checkPalindrome(temp);
	return ans;
}



int main(){
	char str[] = "juggerregguj";
	bool answer = checkPalindrome(str);
	if(answer) {
		cout << "Palindrome";
	} else {
		cout << "Not Palindrome";
	}
}
