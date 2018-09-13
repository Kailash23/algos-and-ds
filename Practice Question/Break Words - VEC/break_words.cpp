/*
   Break words
   You are given a sentence contained in given string S. Write a function which will replace all the words within the sentence whose length is even and greater than equal to 4, with a space between the two equal halves of the word.
   Space complexity should be O(1).
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

void breakWords(char* S) {
	vector<string> words;
	int len = strlen(S);
	string currentWord;

	for(int i=0; i <= len; i++) {
		if((S[i] == ' ' || S[i] == '\0') && !currentWord.empty()) {
			words.push_back(currentWord);
			currentWord = "";
		} else {
			currentWord = currentWord + S[i];
		}
	}

	for(int k = 0; k < words.size(); k++) {
		int n = words[k].size();
		if(n >= 4 && n%2 == 0) {
			int s = n/2;
			words[k].resize(n+1,' ');
			for(int i = n+1; i >= s; i--) {
				words[k][i] = words[k][i-1];
			}
			words[k][s] = ' ';
		}
	}

	for(int i = 0; i < words.size(); i++) {
		int n = words[i].size();
		if(i != words.size()-1) {
			words[i].resize(n+1,' ');
		}
	}

	int ind = 0;
	for(int i = 0; i < words.size(); i++) {
		for(int j = 0; j < words[i].size(); j++) {
			S[ind++] = words[i][j];
		}
	}
	S[ind] = '\0';
}


int main(){
	char str[] = "Call Me Jugger";
	breakWords(str);
}

/*
   Call Me Juggernaut
   Ca ll Me Jugge rnaut
 */
