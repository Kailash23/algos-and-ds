/*
   Check Palindrome (recursive)
   Check if a given String S is palindrome or not (using recursion). Return true or false.
 */

#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char input[]) {
	if (strlen(input) == 0) {    // size 0 taken as palindrome
		return true;
	}
	if (input[0] != input[strlen(input) - 1]) {    	// comparing first and last element
		return false;
	}
	input[strlen(input) - 1] = '\0';	// Placing null character in place of last character.
										// This will decrease the length of string by 1
	return checkPalindrome(input + 1);	// Passing string without first and last character
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

/*
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
 */
