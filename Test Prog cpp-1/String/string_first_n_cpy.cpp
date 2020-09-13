#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char s1[] = {"west"};
    char s2[] = {"world"};
    strncpy(s1, s2, 3);
    cout << s1;
}

/*
   wort
 */

/*
   Append NULL after 'd'
   char s1[] = {"west"};
   char s2[] = {"wd"};
   strncpy(s1,s2,3)
   //Output: wd
 */

// strncpy(dest, source,n);
