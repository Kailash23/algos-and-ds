/*
Make Strings Anagram

Given two strings S1 and S2, find and return the minimum number of deletions to be made (total count of deletions in both strings) in order to make the strings anagram.
Anagram of a string is a string which is its permutation.
For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab" are not.
*/
#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

int makeAnagram(char str1[], char str2[]){
	unordered_map<char,int> map1;
	unordered_map<char,int> map2;

	for(int i=0; i<strlen(str1); i++){
		map1[str1[i]]++;
	}

	for(int i=0; i<strlen(str2); i++){
		map2[str2[i]]++;
	}
	int count = 0;
	unordered_map<char,int>:: iterator it1 = map1.begin();
	unordered_map<char,int>:: iterator it2 = map2.begin();

	while(it1!=map1.end()){
			while(it2!=map2.end()){
			if(map1.count(it2->first)){
				char a = it2->first;
				if(map1[a]>map2[a]){
					count += map1[a]- map2[a];
				}
			} else {
				char a = it2->first;
				count += map2[a];

			}
			it2++;
		}
		it1++;
	}

	it1 = map1.begin();
	it2 = map2.begin();

	while(it2!=map2.end()){
			while(it1!=map1.end()){
			if(map2.count(it1->first)){
				char a = it1->first;
				if(map2[a]>map1[a]){
					count += map2[a] - map1[a];
				}
			} else {
				char a = it1->first;
				count += map1[a];

			}
			it1++;
		}
		it2++;
	}
return count;
}




int main(){
	char s1[] = "holla";
	char s2[] = "bollla";
	makeAnagram(s1,s2);
}
