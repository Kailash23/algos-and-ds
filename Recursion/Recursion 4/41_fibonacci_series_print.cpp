/*
   Print fibonacci series upto n terms.
 */

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void fib(int n) {
    for (int i = 1; i <= n; i++) {
        cout << fibonacci(i) << " ";
    }
}

int main() {
    int n;
    cin >> n;
    fib(n);
}

/*
   8
   1 1 2 3 5 8 13 21
 */
