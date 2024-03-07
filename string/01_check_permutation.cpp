/*
   Given two strings, check if they are permutations of each other. Return true or false.
   Permutation means - length of both the strings should same and should contain same set
   of characters. Order of characters doesn't matter.
 */
#include <iostream>
using namespace std;

bool isPermutation(char str1[], char str2[]) {
    int combinedXOR = 0; // Tracks the XOR of characters in both strings
    int sumStr1 = 0;     // Sum of ASCII values in str1
    int sumStr2 = 0;     // Sum of ASCII values in str2

    for (int i = 0; str1[i] != '\0'; i++) {
        combinedXOR ^= str1[i];
        sumStr1 += str1[i];
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        combinedXOR ^= str2[i];
        sumStr2 += str2[i];
    }

    return (combinedXOR == 0) && (sumStr1 == sumStr2);
}

int main() {
    char str1[] = {"abz"};
    char str2[] = {"azb"};
    bool result = isPermutation(str1, str2);

    cout << (result ? "Yes, they are permutation of each other" : "No, they are permutation of each other") << endl;
}

/*
   Yes, they are permutation of each other
 */
