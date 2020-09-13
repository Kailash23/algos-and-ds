/*
    Triangle of numbers

	Print the following pattern for the given number of rows.
	Pattern for N = 3
	
	    1
	   232
	  34543
 */

#include <iostream>
using namespace std;

int main() {
    int num, n, space, loop, j;
    cin >> n;
    space = n;
    for (loop = 1; loop <= n; loop++) {
        num = loop;
        for (j = 1; j < space; j++) {
            cout << " ";
        }
        space--;

        for (j = 1; j <= loop; j++) {
            cout << num;
            num++;
        }
        num -= 2;
        for (j = 1; j < loop; j++) {
            cout << num;
            num--;
        }
        cout << "\n";
    }
}

/*

Input: 5

       1
      232
     34543
    4567654
   567898765

 */
