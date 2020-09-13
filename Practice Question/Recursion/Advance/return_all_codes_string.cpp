/*
   Return all codes - String

   Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a
   numeric string S. Write a program to return the list of all possible codes that
   can be generated from the given string.
   Note : The order of codes are not important. And input string does not contain 0s.

   Input:
   1123

   Output:
   aabc
   kbc
   alc
   aaw
   kw
 */

#include <iostream>
using namespace std;

int getCodes(string input, string output[10000]) {
    if (input.size() == 0) {
        output[0] = "";
        return 1;
    }
    int first = input[0] - '0'; // input[0] - 48;
    char firstChar = 'a' + (first - 1);
    char secondChar = '\0'; // as 0 is for int

    string smallOutput1[500];
    string smallOutput2[500];

    int smallOutputSize1 = getCodes(input.substr(1), smallOutput1);
    int smallOutputSize2 = 0; // as '\0' for char

    if (input[1] != '\0') {
        int second = (first * 10) + (input[1] - '0');
        secondChar = 'a' + (second - 1);
        if (second >= 10 && second <= 26) {
            smallOutputSize2 = getCodes(input.substr(2), smallOutput2);
        }
    }
    int k = 0;
    for (int i = 0; i < smallOutputSize1; i++) {
        output[k++] = firstChar + smallOutput1[i];
    }
    for (int i = 0; i < smallOutputSize2; i++) {
        output[k++] = secondChar + smallOutput2[i];
    }
    return k;
}

int main() {
    string str = "1123";
    string output[1000];
    int len = getCodes(str, output);
    for (int i = 0; i < len; i++) {
        cout << output[i] << endl;
    }
}

/*
   aabc
   aaw
   alc
   kbc
   kw
 */
