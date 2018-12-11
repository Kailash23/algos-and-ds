/*
   Break words
   You are given a sentence contained in given string S. Write a function which
   will replace all the words within the sentence whose length is even and greater
   than equal to 4, with a space between the two equal halves of the word.
   Space complexity should be O(1).
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

void breakWords(char* S) {
	int n = strlen(S);
	int ind = 0;
	vector<string> strWords;
	string currentWord, str;

	for(int i = 0; i <= n; i++) {	// <= for including '\0'
		if((S[i] == ' ' || S[i] == '\0') &&  !currentWord.empty()) {
			strWords.push_back(currentWord + " ");
			currentWord.clear();
		} else {
			currentWord += S[i];
		}
	}

	for(int k = 0; k < strWords.size(); k++) {
		int n = strWords[k].length() - 1;	// -1 for space that we added
		int s = n / 2;
		if(n >= 4 && n % 2 == 0) {
			for(int i = n + 1; i >= s; i--) {
				strWords[k][i + 1] = strWords[k][i];
			}
			strWords[k][s] = ' ';
		} else {
			strWords[k].resize(n);
		}
	}

	for(int i = 0; i < strWords.size(); i++) {
		str += strWords[i];
		str += ' ';
	}

	for(int j = 0; j < str.length(); j++) {
		S[ind++] = str[j];
	}

	for(int j = 0; j < str.length(); j++) {
		cout << S[j];
	}
}


int main(){
	char s[] = {"Call me juggernaut"};
	breakWords(s);
}

/*
   Ca ll me jugge rnaut
 */
