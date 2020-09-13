/*
   Print Keypad Combinations Code

   Given an integer n, using phone keypad find out and print all the possible strings
   that can be made using digits of input n.
   Note : The order of strings are not important. Just print different strings in
   new lines.
 */

#include <iostream>
using namespace std;

string code[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypadHelper(int num, string output) {
    if (num == 0) {
        cout << output << endl;
        return;
    }
    int appendNum = num % 10;
    for (int i = 0; i < code[appendNum].size(); i++) {
        printKeypadHelper(num / 10, code[appendNum][i] + output);
    }
}

void printKeypad(int num) {
    string output;
    printKeypadHelper(num, output);
}

int main() {
    int n = 23;
    printKeypad(n);
}
