/*
   Palindrome substrings
   Given a string S, count and return the number of substrings of S that are palindrome.
   Single length substrings are also palindromes. You just need to calculate the count,
   not the substrings.
 */

// Time:- O(n^3)

#include <iostream>
#include <cstring>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int checkPalindrome(char s[]){
	int n = strlen(s);
	int start = 0, end = n - 1;

	char temp[n];
	int ind = 0;

	for(int k = 0; s[k] != '\0'; k++) {     // Making copy of s array (temp)
		temp[ind++] = s[k];
	}

	temp[ind] = '\0';

	while(start <= end) {       // Reversing temp array
		swap(temp[start], temp[end]);
		start++;
		end--;
	}

	if(strcmp(s, temp) == 0) {      // Comparing s and temp
		return 1;
	} else {
		return 0;
	}
}

int countPalindromeSubstrings(char s[]) {
	int i = 0, j = 0;
	int n = strlen(s);
	int count = 0;

	while(i < n) {
		j = i;
		while(j < n) {
			char temp[j - i + 1];	// +1 for storing '\0'
			int ind = 0;
			for(int k = i; k <= j; k++) {
				temp[ind++] = s[k];
			}
			temp[ind] = '\0';
			count += checkPalindrome(temp);
			j++;
		}
		i++;
	}
	return count;
}

int main(){
	char arr[] = {"abac"};
	cout << countPalindromeSubstrings(arr);
}

/*
   5
 */
