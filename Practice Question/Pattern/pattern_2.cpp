#include <iostream>
using namespace std;

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
        int space = n - i - 1;
        while (space > 0) {
            cout << " ";
            space--;
        }
        int count = i + 1;
        for (int j = 0; j < i + 1; j++) {
            cout << count++;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    printPattern(n);
}

/*
	5
	    1
	   23
	  345
	 4567
	56789
*/
