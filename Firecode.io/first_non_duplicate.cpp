/*
   Find the first non-duplicate character in a string. Return '0' if no unique
   character is found.

   first_non_repeating( "abcdcd" ) --> 'a'
   first_non_repeating( "cbcd" ) --> 'b'
   first_non_repeating( "cdcd" ) --> '0'
 */

#include <unordered_map>

char first_non_repeating(string str) {
    unordered_map<char, int> map;
    for (int i = 0; i < str.size(); i++) {
        map[str[i]]++;
    }
    char c = '0';
    for (int i = 0; i < str.size(); i++) {
        if (!(map[str[i]] > 1)) {
            c = str[i];
            break;
        }
    }
    return c;
}
