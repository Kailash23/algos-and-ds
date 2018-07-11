/*
Find smallest substring

Given two strings string1 and string2 (named large and small), find the smallest substring in string1 containing all characters of string2 in O(n). You need to return the output substring.
Note : The characters of string2 need not to be present in same order in string1. That is, we need a substring which contains all characters of string2 irrespective of the order.
Return null if no substring with all characters is present.
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;

void findMinSubstringContainingString(char *large, char *small){

	vector<char> v;
	vector<char> mv;
	char str[50];

	unordered_map<char,int> map;
	for(int i=0;i<strlen(small);i++){
		map[small[i]]++;
	}
	map[' '] = 1;

	for(int i=0;i<strlen(large);i++){
		v.clear();
		int c = i;
		while(map.count(large[c]) > 0){
			v.push_back(large[c]);
			c++;
		}

		if(v.size() > mv.size()){
			mv = v;
		}
	}

	vector<char>::iterator it1 = mv.begin();
	int s =0;
	while(it1 != mv.end()){
		str[s++] = *it1;
		it1++;
	}
	str[s] = '\0';
	cout<<str;
}


int main(){
	char large[] = "gg prabhee";
	char small[] = "ash praa";
	findMinSubstringContainingString(large, small);
}
