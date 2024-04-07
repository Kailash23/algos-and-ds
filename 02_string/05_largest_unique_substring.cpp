/*
   Given a string S, find the largest substring with no repetition i.e,
   largest substring which contain all unique characters.
 */

#include <cstring>
#include <iostream>
#include <map>
using namespace std;

void findLargestUniqueSubstring(char input[]) {
    map<string, int> substringToLenMap;
    map<char, bool> occurrenceTrackingMap;

    int subStrLen = 0;
    string subStr = "";
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        bool isCharExists = occurrenceTrackingMap.count(input[i]) > 0;

        if (!isCharExists) {
            occurrenceTrackingMap[input[i]] = true;
            subStrLen++;
            subStr += input[i];
        } else {
            substringToLenMap[subStr] = subStrLen;
            // Reset
            occurrenceTrackingMap.clear();
            occurrenceTrackingMap[input[i]] = true;
            subStrLen = 1;
            subStr = "";
            subStr += input[i];
        }
    }

    if (subStr.length() > 0) {
        substringToLenMap[subStr] = subStr.length();
    }

    string maxSubStr = "";
    int maxLen = 0;

    for (const auto &pair : substringToLenMap) {
        if (pair.second > maxLen) {
            maxSubStr = pair.first;
            maxLen = pair.second;
        }
    }

    cout << maxSubStr << endl;
}

int main() {
    char input[] = "abcdabcd";
    int n = strlen(input);
    findLargestUniqueSubstring(input);
}

/*
   abcdabcd
 */

/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */