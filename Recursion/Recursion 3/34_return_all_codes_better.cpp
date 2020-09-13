/*
   Return all codes - String

   Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a
   numeric string S.
   Write a program to return the list of all possible codes that can be generated
   from the given string.
   Note : The order of codes are not important. And input string does not contain 0s.
 */

#include <iostream>
using namespace std;

int getCodes(string input, string output[]) {
    if (input[0] == '\0') {
        output[0] = "";
        return 1;
    }
    int first = input[0] - '0';         // input[0] - 48;	coverting char to int '1'==>1
    char firstChar = 'a' + (first - 1); // converting 1 (int) to its code ie 'a'
    char secondChar = '\0';             // (as 0 for int) for char we can initial as '\0' ie empty

    string smallOutput1[500]; // empty output arrays
    string smallOutput2[500];

    int smallOutputSize1 = getCodes(input.substr(1), smallOutput1);
    int smallOutputSize2 = 0;

    if (input[1] != '\0') {
        int second = (first * 10) + (input[1] - '0');
        if (second >= 10 && second <= 26) { // If True thus we can deduce int to char code
            secondChar = (second - 1) + 'a';
            smallOutputSize2 = getCodes(input.substr(2), smallOutput2);
        }
    }
    int k = 0;
    for (int i = 0; i < smallOutputSize1; i++) {
        output[k] = firstChar + smallOutput1[i];
        k++;
    }
    for (int i = 0; i < smallOutputSize2; i++) {
        output[k] = secondChar + smallOutput2[i];
        k++;
    }
    return k;
}

int main() {
    string str = "1123";
    string output[1000];
    int outLen = getCodes(str, output);
    for (int i = 0; i < outLen; i++) {
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
