/*
   Code : No. of numbers - with duplicates

   Given a number n, find number of numbers that are greater than n using the same set of digits as n. n didnt have any duplicate digits.
 */

#include <iostream>
using namespace std;

int num(int *input, int n, int *fact, int *freq) {
    if (n == 0 || n == 1) { // If number of digit is 1 or 0 then return 0 as no number can be formed form that single digit greater than it.
        return 0;
    }
    int ans = 0;
    for (int i = input[0] + 1; i < 10; i++) { // Starting from number greater then that number upto 10
        if (freq[i] > 0) {                    // We will check the freq of that number in freq array.
            ans += fact[n - 1];               // Adding factorial of n-1 to the answer, where n is num of digits.
        }
    }
    freq[input[0]]--; // We will decrement the freq of digit at zero place index as we call recursion on the other places which will not include that number again.
    ans += num(input + 1, n - 1, fact, freq);
    return ans;
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    int *fact = new int[n + 1];
    fact[0] = 1;
    int freq[10] = {};
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        freq[input[i]]++;
        fact[i + 1] = (i + 1) * fact[i];
    }
    cout << num(input, n, fact, freq) << endl;
}
