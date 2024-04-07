/*
   Given a string S, reverse each word of a string individually.
   For eg. if a string is "abc def", reversed string should be "cba fed".
 */

#include <cstring> // for strlen
#include <iostream>
using namespace std;

void reverseSegment(char input[], int start, int end) {
    while (start < end) {
        swap(input[start], input[end]);
        start++;
        end--;
    }
}

char *reverseEachWord(char input[]) {
    int wordStart = 0;
    int stringLength = strlen(input);

    for (int currentIndex = 0; currentIndex <= stringLength; currentIndex++) {
        if (input[currentIndex] == ' ' || input[currentIndex] == '\0') {
            reverseSegment(input, wordStart, currentIndex - 1);
            wordStart = currentIndex + 1;
        }
    }
    return input;
}

int main() {
    char inputString[] = "Hello, this is a test";
    char *reversedString = reverseEachWord(inputString);
    cout << reversedString << endl;
}

/*
   ,olleH siht si a tset
 */
