#include <iostream>
using namespace std;

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j + 1;
        }
        for (int k = (2 * n) - 2; k > (2 * i); k--) {
            cout << " ";
        }
        for (int l = i + 1; l > 0; l--) {
            cout << l;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    printPattern(n);
}
