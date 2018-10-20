#include <iostream>
using namespace std;

int main(){
	int y = 1;
	if(y & (y = 2)) {
		cout << "true";
	} else {
		cout << "false";
	}
}

/*
   true
 */

/*
   Bitwise operator is suitable for turning off a particular bit in a number. - &
   Bitwise operator is suitable for turning on a particular bit in a number. - |
   Bitwise operator is suitable for checking whether a particular bit is on or off. &, | and ^

   x & 1 = x
   x | 0 = x
   x ^ 0 = x
 */
