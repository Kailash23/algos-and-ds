/*
   Code : Flip ith bit

   You are given two integers N and i.
   Counting of bits start from 0 from right to left.
 */

#include <iostream>
using namespace std;

int flipIthBit(int n, int i) {
    n = n ^ (1 << i);
    return n;
}

int main() {
    int n, i;
    cin >> n >> i;
    cout << flipIthBit(n, i);
}

/*
   7 4
   23
 */

/*
   16 8 4 2 1
    0 0 1 1 1

   1 0 0 0 0
   0 0 1 1 1
  -----------
   1 0 1 1 1  (23)

 */
