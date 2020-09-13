/*
	Print the pattern

	Print the following pattern for the given number of rows.
	Pattern for N = 5

	1 2 3 4 5
	11 12 13 14 15
	21 22 23 24 25
	16 17 18 19 20
	6 7 8 9 10
 */

#include <iostream>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i += 2) {
        for (int j = 1; j <= n; j++) {
            cout << (n * i + j) << " ";
        }
        cout << endl;
    }
    if (n % 2) {
        i -= 2;
    }
    for (i--; i > 0; i -= 2) {
        for (int j = 1; j <= n; j++) {
            cout << (n * i + j) << " ";
        }
        cout << endl;
    }
}

/*
   Input: 5
   1 2 3 4 5
   11 12 13 14 15
   21 22 23 24 25
   16 17 18 19 20
   6 7 8 9 10
 */
