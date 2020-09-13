/*
   Write a function that takes an input string - str and returns true if all the
   characters in the string are unique, false if there is even a single repeated
   character.

   For an empty string, return true.

   Examples:

   are_all_characters_unique("abcde") -> true
   are_all_characters_unique("aa") -> false
   are_all_characters_unique("") -> true
 */

#include <unordered_map>

bool are_all_characters_unique(string str) {
    if (str == "") {
        return true;
    }
    unordered_map<char, int> map;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
        if (map[str[i]] >= 1) {
            return false;
        }
        map[str[i]]++;
    }
    return true;
}
