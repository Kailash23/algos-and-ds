#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char s1[] = "Hello"; //500
    char s2[] = "World";
    int i, j;
    i = strcmp(s1, "Hello");
    j = strcmp(s1, s2);
    cout << i << endl; //0
    cout << j << endl; //-15
    return 0;
}

/*
   If the two strings are identical, it returns a 0. If not, then it
   returns the difference between the ASCII values of the first non-matching
   pairs of characters.
 */
