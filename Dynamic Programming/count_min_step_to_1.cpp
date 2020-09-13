/*
   Code : Min Steps to 1

   Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.
   1.) Subtract 1 from it. (n= n - ­1) ,
   2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
   3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).
   The time complexity of your code should be O(n).
 */

#include <iostream>
#include <math.h>
using namespace std;

int getMinSteps(int n, int memo[]) {

    if (n == 1) { // if n is already 1 then we dont have to take any step so we return 0.
        return 0;
    }

    if (memo[n] != -1) { // if we have computed min steps for n then use it (optimization)
        return memo[n];
    }

    // We gonna store temp values for n as min(f(n-1), f(n/2), f(n/3)) + 1

    int res = getMinSteps(n - 1, memo); // Getting result (no of steps) for n-1

    if (n % 2 == 0) {
        res = min(res, getMinSteps(n / 2, memo)); // We will choose minimum of steps needed for (n-1 then n/2 or n/3) or (n then n/2 or n/3).
    }

    if (n % 3 == 0) {
        res = min(res, getMinSteps(n / 3, memo)); // We will choose minimum of steps needed for n-1 and n/3.
    }

    memo[n] = 1 + res; // store memo[n] and return
    return memo[n];
}

int countStepsTo1(int n) {
    int *memo = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    return getMinSteps(n, memo);
}

int main() {
    int n;
    cin >> n;
    cout << countStepsTo1(n);
}

/*
   Time complexity would have been 3^n if it were a recursive solution without memoization, but since here we are using memoization to store the values so the time complexity reduces to O(n).
 */
