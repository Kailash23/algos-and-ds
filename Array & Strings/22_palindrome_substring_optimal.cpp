/*
   Palindrome substrings
   Given a string S, count and return the number of substrings of S that are palindrome.
   Single length substrings are also palindromes. You just need to calculate the
   count, not the substrings.
 */

#include <iostream>
#include <cstring>
using namespace std;

int countPalindromeSubstrings(char s[]) {
	int left = 0, right = 0;
	int mid, start = 0, end = 0;
	int count = 0;
	int flag = 1, mid1, mid2;
	int i = 0, j = 0, n;
	n = strlen(s);

	// Counting odd palindrome substring

	while(s[i] != '\0') {
		count++;	// count is incremented as single letter is count as pallindrome
		mid = i;
		left = mid - 1;
		right = mid + 1;
		flag = 1;

		while(left >= 0 && right < n && flag != 0) {		// We will not loop again if we get any sequence  that isn't pallindrome. ie flag = 0
			start = left;
			end = right;
			flag = 1;
			while(start <= end) {
				if(s[start] != s[end]) {
					flag = 0;		// flag 0 ie not pallindrome
				}
				start++;
				end--;
			}
			if(flag == 1) {
				count++;		// if flag = 1 increment count
			}
			left--;
			right++;
		}

		i++;
	}

	flag = 1;	// reset flag

	// Counting even palindrome substring

	while(s[j] != '\0') {
		mid1 = j;		// taking two element as mid and checking pallindrome around them
		mid2 = j + 1;
		if(s[mid1] == s[mid2]) {
			count++;		// count is incremented because 2 same letter string is pallindrome
			left = mid1 - 1;
			right = mid2 + 1;
			flag = 1;
			while(left >= 0 && right < n && flag != 0) {
				start = left;
				end = right;
				flag = 1;
				while(start <= end) {
					if(s[start] != s[end]) {
						flag = 0;
					}
					start++;
					end--;
				}
				if(flag == 1) {
					count++;
				}
				left--;
				right++;
			}
		}
		j++;
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
