#include <iostream>
using namespace std;

int main(){
	char c = 'A';
	char d = c + 32;
	cout << d << endl;
}

/*
   The ASCII codes for a-z are 97-122.
   The ASCII codes for A-Z are 65-90.

   To get A from a, you need to subtract 32.
   To get a from A, you need to add 32.

   To make the code a little more clear, you can use:

        s[i] += ('a' - 'A');
        // 'a' = 'A' + ('a' - 'A');
   when converting an uppercase letter to a lowercase letter and

        s[i] += ('A' - 'a');
        // 'A' = 'a' + ('A' - 'a');
   when converting a lowercase letter to an uppercase letter.
 */
