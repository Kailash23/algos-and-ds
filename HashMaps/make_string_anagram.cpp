/*
   Make Strings Anagram

   Given two strings S1 and S2, find and return the minimum number of deletions
   to be made (total count of deletions in both strings) in order to make the
   strings anagram. Anagram of a string is a string which is its permutation.
   For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab"
   are not.

   Input:
   cde
   abc
   Output:
   4

   Input:
   aab
   aba
   Output:
   0
 */

#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int makeAnagram(char str1[], char str2[]){
	unordered_map<char,int> map1;
	unordered_map<char,int> map2;

	for(int i=0; i<strlen(str1); i++) {
		map1[str1[i]]++;
	}

	for(int i=0; i<strlen(str2); i++) {
		map2[str2[i]]++;
	}

	int count = 0;
	unordered_map<char,int> :: iterator it1 = map1.begin();
	unordered_map<char,int> :: iterator it2 = map2.begin();

	while(it2 != map2.end()) {		// Traverse map2 and check whether its value present in map1 or not.
		char a = it2->first;
		if(map1.count(it2->first) > 0) {	// If a present in map1
			if(map1[a] > map2[a]) {		// If count of char a is greater in map1
				count += (map1[a] - map2[a]);		//count - extra element to be deleted - is the difference between count of a char in map1 and map2
			}
		} else {
			count += map2[a];		//If not present in map1 simply add count of char a in map2 to count.
		}
		it2++;
	}

	it1 = map1.begin();
	it2 = map2.begin();

	while(it1 != map1.end()) {		// Traverse map1 and check whether its value present in map2 or not.
		char a = it1->first;
		if(map2.count(it1->first) > 0) {		// If a present in map2
			if(map2[a] > map1[a]) {		// If count of char a is greater in map2
				count += (map2[a] - map1[a]);		//count - extra element to be deleted - is the difference between count of a char in map2 and map1
			}
		} else {
			count += map1[a];		//If not present in map2 simply add count of char a in map1 to count.
		}
		it1++;
	}
	return count;
}

int main(){
	char s1[] = "holla";
	char s2[] = "bollla";
	cout << makeAnagram(s1, s2);
}

/*
   3
   (h,b and l to be deleted)
 */
