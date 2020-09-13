/*
   Number of Digits

   Given the code to find out and return the number of digits present in a number
   recursively. But it contains few bugs, that you need to rectify such that all
   the test cases should pass.
 */

#include <iostream>
using namespace std;

int count(int n) {
    if (n == 0) {
        return 0;
    }
    return count(n / 10) + 1;
}

int main() {
    int a = 231995;
    cout << count(a);
}

/*
   6
 */

/*
    int c = 0;
    int count(int n){
        if(n<10) {
            c++;
            return c;
        }
        c++;
        count(n/10);
    }
 */
