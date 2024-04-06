/*
   Reverse string Word Wise

   Reverse the given string word wise. That is, the last word in given string should
   come at 1st place, last second word at 2nd place and so on. Individual words should
   remain as it is.
 */

#include <cstring>
#include <iostream>

using namespace std;

void reverseWord(int startInd, int endInd, char input[]) {
    while (startInd < endInd) {
        swap(input[startInd], input[endInd]);
        startInd++;
        endInd--;
    }
}

void reverseStringWordWise(char input[]) {
    int len = strlen(input);
    reverseWord(0, len - 1, input);
    int wordStartIndex = 0;

    for (int charIndex = 0; charIndex < len + 1; charIndex++) {
        if (input[charIndex] == ' ' || input[charIndex] == '\0') {
            reverseWord(wordStartIndex, charIndex - 1, input);
            wordStartIndex = charIndex + 1;
        }
    };
}

int main() {
    char arr[] = {"Reverse String Word Wise!"};
    reverseStringWordWise(arr);
    cout << arr << endl;
};
