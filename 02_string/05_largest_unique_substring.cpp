/*
   Given a string S, find the largest substring with no repetition i.e,
   largest substring which contain all unique characters.
 */

#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;

void findLargestUniqueSubstring(char input[]) {
    unordered_map<char, int> charIndexMap; // To maintain last seen position of char
    int start = 0;                         // Start index of the current window
    int maxLength = 0;                     // Length of the longest substring found so far
    string longestSubString;               // Stores the longest substring found so far
    string inputStr = input;

    for (int end = 0; input[end] != '\0'; end++) {
        char currentChar = input[end];

        bool isCharFound = charIndexMap.count(currentChar) > 0;
        bool isCharWithinCurrentWindow = charIndexMap[currentChar] >= start;
        // If the character is already in the map and its last seen position is within the current window

        if (isCharFound && isCharWithinCurrentWindow) {
            start = charIndexMap[currentChar] + 1;
        }

        // Update the last seen position
        charIndexMap[currentChar] = end;

        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            longestSubString = inputStr.substr(start, maxLength);
        }
    }
    cout << "Largest unique substring: " << longestSubString << endl;
}

int main() {
    char input[] = "abcabbbbdsakleiu";
    int n = strlen(input);
    findLargestUniqueSubstring(input);
}

/*
   bdsakleiu
 */

/**
 * Time Complexity: O(n)
 *
 * The algorithm still makes a single pass through the input string of length n,
 * resulting in an O(n) component for traversing the entire string.
 *
 * With std::unordered_map, both checking for a character's existence and updating
 * its last seen position ideally have average-case time complexities of O(1)
 *
 * However, in the worst-case scenario (e.g., many hash collisions), these operations
 * can degrade to O(m), where m is the number of unique characters.
 *
 * Combining these, the average-case time complexity of the algorithm using std::unordered_map is O(n), assuming hash operations (insertion, access) generally execute in constant time.
 *
 *
 * Space Complexity: O(m) - where m is the number of unique characters in the input string.
 */