/*
   Check Palindrome (recursive)

   Check if a given String S is palindrome or not (using recursion). Return true
   or false.
 */

#include <iostream>
using namespace std;

bool checkPalindrome(string input) {
    if (input.size() <= 1) {
        return true;
    }
    bool smallAns;
    if (input[0] == input[input.size() - 1]) {
        smallAns = true;
    } else {
        smallAns = false;
    }
    return smallAns && checkPalindrome(input.substr(1, input.size() - 2));
}

int main() {
    string str;
    getline(cin, str);
    if (checkPalindrome(str)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }
}

/*
   acddca
   Palindrome
 */
