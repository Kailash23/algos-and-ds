/*
   Remove Duplicates Recursively

   Given a string S, remove consecutive duplicates from it recursively.

   Sample Input :
   aabccba
   Sample Output :
   abcba

 */
#include <iostream>
#include <string.h>
using namespace std;

string removeConsecutiveDuplicates(string input) {
    if (input.length() <= 1) {
        return input;
    }
    if (input[0] == input[1]) {
        return removeConsecutiveDuplicates(input.substr(1));
    } else {
        return input[0] + removeConsecutiveDuplicates(input.substr(1));
    }
}

int main() {
    string str = "abbcccdef";
    cout << removeConsecutiveDuplicates(str);
}
