/*
   Reverse string Word Wise

   Reverse the given string word wise. That is, the last word in given string should
   come at 1st place, last second word at 2nd place and so on. Individual words should
   remain as it is.
 */

#include <cstring>
#include <iostream>

using namespace std;

void reverse(char arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void reverseStringWordWise(char input[]) {
    int len = strlen(input);
    reverse(input, 0, len - 1); // reversing the whole string

    int start = 0;
    int end = 0;

    for (int i = 0; i <= len; i++) { // Now reversing each word
        if (input[i] == ' ' || input[i] == '\0') {
            end = i - 1; // end will be alphabet before space or \0
            reverse(input, start, end);
            start = i + 1; // start for the next word will be next char after space
        }
    }
    cout << input << endl;
}

int main() {
    char arr[] = {"Reverse String Word Wise!"};
    reverseStringWordWise(arr);
}
