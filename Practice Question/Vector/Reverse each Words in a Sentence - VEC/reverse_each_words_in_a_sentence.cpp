#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_words(string str) {
	vector<string> words;
	int len = str.length();
	string currentWord;
	for(int i=0; i <= len; i++) {
		if(str[i] == ' ' || str[i] == '\0') {
			words.push_back(currentWord);
			currentWord = "";
		} else {
			currentWord = currentWord + str[i];
		}
	}
	return words;
}


int main(){
	string str = "Call Me Juggernaut";
	vector<string> words = split_words(str);

	for(int i = 0; i < words.size(); i++) {
		reverse(words[i].begin(), words[i].end());
	}

	for(int i = 0; i < words.size(); i++) {
		cout<< words[i] <<" ";
	}
}

/*
   Call Me Juggernaut
   llaC eM tuanregguJ
 */
