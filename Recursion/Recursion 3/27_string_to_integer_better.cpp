/*
   String to Integer

   Write a recursive function to convert a given string into the number it
   represents. That is input will be a numeric string that contains only numbers,
   you need to convert the string into corresponding integer and return the answer.
 */

#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;

int convert(char input[], int size) {
    if (strlen(input) == 1) {
        return input[0] - '0';
    }
    int smallOutput = convert(input + 1, size - 1); // operating from front of array
    int firstDigit = input[0] - '0';
    int depth = 1;
    for (int i = 0; i < size - 1; i++) {
        depth *= 10;
    }
    return (firstDigit * depth) + smallOutput;
}

int stringToNumber(char input[]) {
    int s = strlen(input);
    return convert(input, s);
}

int main() {
    char arr[] = "27812718";
    int size = strlen(arr);
    int n = stringToNumber(arr);
    cout << n;
}

/*
   27812718
 */
