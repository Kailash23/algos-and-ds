#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

void breakWords(char* S) {
	int n = strlen(S);
	int ind=0;
	vector<string> strWords;
	string currentWord,str;
	for(int i=0;i<=n;i++){
		if((S[i] == ' ' || S[i]=='\0') &&  !currentWord.empty()){
			strWords.push_back(currentWord+" ");
			currentWord.clear();
		} else {
			currentWord += S[i];
		}
	}

	for(int k=0;k<strWords.size();k++){
		int n = strWords[k].length()-1;
		int s = n/2;
		if(n>=4 && n%2==0){
			for(int i=n+1;i>=s;i--){
				strWords[k][i+1]=strWords[k][i];
			}
			strWords[k][s]=' ';
 		} else {
			strWords[k].resize (n,' ');
		}
	}

	for(int i=0;i<strWords.size();i++){
		str+=strWords[i];
		str+=' ';
	}

	for(int j=0;j<str.length();j++){
		S[ind++] = str[j];
	}
}


int main(){
	char s[]={"Call me juggernaut uniyal"};
	breakWords(s);
}
