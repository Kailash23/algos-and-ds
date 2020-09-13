/*
   Program to retun all the subsequence of a string.
 */

#include <iostream>
#include <math.h>
using namespace std;

int returnSubsequence(string input, string output[]) {
    if (input.size() == 0) {
        output[0] = "";
        return 1;
    }
    int smallOutputSize = returnSubsequence(input.substr(1), output);
    for (int i = 0; i < smallOutputSize; i++) {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main() {
    string input = "abc";
    int n = input.size();
    int size = pow(2, n);
    string *output = new string[size];
    int num = returnSubsequence(input, output);
    for (int i = 0; i < num; i++) {
        cout << output[i] << endl;
    }
}

/*

   c
   b
   bc
   a
   ac
   ab
   abc
 */
