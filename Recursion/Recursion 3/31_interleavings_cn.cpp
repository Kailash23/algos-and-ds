/*
   Interleavings

   Given two strings S (of length m) and T (of length n), you need to find and
   print out all the possible inter leavings that are possible of length (m + n).
   Inter leaving means - all possible combination of characters from both strings
   such that it contain all characters from both strings and, the respective
   ordering of characters of one string should remain same as in original.
   For eg.
   S = ab
   T = cd
   You need to find all strings of length 4 that contain all characters 'a', 'b',
   'c' & 'd'. The only constraint on ordering of characters is - 'a' should always
   come before 'b' and 'c' should always come before 'd'.
   Note : Print all strings in different lines.
 */

#include <cstring>
#include <iostream>
using namespace std;

void interleavingHelper(char *first, char *second, char *output, int outputIndex = 0) {
    if (first[0] == '\0' && second[0] == '\0') {
        output[outputIndex] = '\0';
        cout << output << endl;
        return;
    }
    if (first[0] != '\0') {
        output[outputIndex] = first[0];
        interleavingHelper(first + 1, second, output, outputIndex + 1);
    }
    if (second[0] != '\0') {
        output[outputIndex] = second[0];
        interleavingHelper(first, second + 1, output, outputIndex + 1);
    }
}

void interleavings(char *first, char *second) {
    int m = strlen(first);
    int n = strlen(second);
    char *output = new char[m + n + 1];
    interleavingHelper(first, second, output);
    delete[] output;
}

int main() {
    char s1[] = "a";
    char s2[] = "cd";
    interleavings(s1, s2);
}

/*
   acd
   cad
   cda
 */
