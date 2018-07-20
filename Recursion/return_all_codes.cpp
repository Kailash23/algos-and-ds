/*
Return all codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
*/

#include<iostream>
#include<string.h>
using namespace std;

int getCodesHelper(string input, int startIndex, int length, string output[1000]){
	if(startIndex == length){
		return 1;
	}

	string output1[1000];
	string output2[1000];

	int smallOutput1 = getCodesHelper(input, startIndex+1, length, output1);
	int smallOutput2 = 0;

	int num1 = input[startIndex]-'0';

	for(int i=0;i<smallOutput1;i++){
		char c1 = (num1+'a'-1);
		output[i] = c1 + output1[i];
	}

	if(length-startIndex>1){
		int num2 = (input[startIndex]-'0')*10 + (input[startIndex+1]-'0');
		if(num2 <=26){
			smallOutput2 = getCodesHelper(input,startIndex+2,length,output2);

			for(int i= smallOutput1; i<smallOutput1+smallOutput2;i++){
				char c2 = (num2+'a'-1);
				output[i] = c2 + output2[i-smallOutput1];
			}
		}
	}
	return (smallOutput1 + smallOutput2);
}

int getCodes(string input, string output[1000]) {
	int len = input.size();
	return getCodesHelper(input,0,len,output);
}

int main(){
	string str = "1123";
	string output[1000];
	int outLen = getCodes(str, output);
	for(int i=0;i<outLen;i++){
		cout<<output[i]<<endl;
	}
}
