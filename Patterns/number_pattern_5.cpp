/*
	Number Pattern

	Print the following pattern for n number of rows.
	For eg. N = 5

	1        1
	12      21
	123    321
	1234  4321
	1234554321

*/

#include <iostream>
using namespace std;

int main() {
    int n, space, i;
    cin >> n;
    space = 2 * (n - 1);
    for (i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        space -= 2;
        for (int j = i; j > 0; j--) {
            cout << j;
        }
        cout << endl;
    }
}

/*
   Input: 7
   1            1
   12          21
   123        321
   1234      4321
   12345    54321
   123456  654321
   12345677654321

 */
