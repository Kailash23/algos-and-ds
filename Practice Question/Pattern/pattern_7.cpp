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

void printPattern(int n){
	int li = 1, ri = (n * n) - n + 1;
	int i = 0;
	if(n % 2 == 0) {
		while(i < n / 2) {
			for(int j = li; j < li + n; j++) {
				cout << j << " ";
			}
			cout << endl;
			li += (2 * n);
			i++;
		}
		while(i < n) {
			for(int j = ri; j < ri + n; j++) {
				cout << j << " ";
			}
			cout << endl;
			ri -= (2 * n);
			i++;
		}
	} else {
		while(i < n / 2) {
			for(int j = li; j < li + n; j++) {
				cout << j << " ";
			}
			cout << endl;
			li += (2 * n);
			i++;
		}
		for(int j = ri; j < ri + n; j++) {
			cout << j << " ";
		}
		cout << endl;
		ri -= n;
		i++;
		while(i < n) {
			for(int j = ri; j < ri + n; j++) {
				cout << j << " ";
			}
			cout << endl;
			ri -= (2 * n);
			i++;
		}
	}
}

int main(){
	int n;
	cin >> n;
	printPattern(n);
}

/*
   6
   1 2 3 4 5 6
   13 14 15 16 17 18
   25 26 27 28 29 30
   31 32 33 34 35 36
   19 20 21 22 23 24
   7 8 9 10 11 12

 */

/*
    void printPattern(int n) {
        int startValue = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = startValue; j < startValue + n; j++) {
                cout << j << " ";
            }
            cout << "\n";
            if (i == (n + 1) / 2) {
                if (n % 2 != 0) {
                    startValue = n * (n - 2) + 1;
                } else {
                    startValue = n * (n - 1) + 1;
                }
            } else if (i > (n + 1) / 2) {
                startValue = startValue - 2 * n;
            } else {
                startValue = startValue + 2 * n;
            }
        }
    }
 */
