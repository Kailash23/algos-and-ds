/*
Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.
*/
#include<iostream>
#include<cstring>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	//cout<<input<<endl;
	if(strlen(input)<=1){
		return;
	}
	if(input[0] == input[1]){
		int i = 1;
		for(;input[i] != '\0';i++){
			input[i-1] = input[i];
		}
		input[i-1] = '\0';
		removeConsecutiveDuplicates(input);
	} else {
		removeConsecutiveDuplicates(input+1);
	}
}

int main(){
	char str[] = "aaaabbbddd";
	removeConsecutiveDuplicates(str);
	cout<<str;
}
