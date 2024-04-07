/*
   Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
   For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
 */
#include <cstring>
#include <iostream>
using namespace std;

char *stringCompression(char input[]) {
    int outputIndex = 0;
    char currentChar;
    int charCount = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        currentChar = input[i];
        input[outputIndex++] = currentChar;

        // Count how many times 'currentChar' occurs consecutively
        while (currentChar == input[i]) {
            charCount++;
            i++;
        }

        i--;

        if (charCount > 1) {
            input[outputIndex++] = '0' + charCount; // This will convert integer to string
        }
        charCount = 0;
    }
    input[outputIndex] = '\0';
    return input;
}

int main() {
    char str[] = {"aaabbbccccdddddddeeeegggggk"};
    char *compressedStr = stringCompression(str);
    cout << compressedStr << endl;
}

/*
   a3b3c4d7e4g5k
 */
