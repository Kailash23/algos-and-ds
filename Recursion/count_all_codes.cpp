/*
Count the number of possible codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to count the no of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
*/

#include<iostream>
#include<string>
using namespace std;

int getInteger(string num){
	int len = num.length();
	if(len == 1){
		return num[0]-'0';
	} else if (len == 2){
		int n,k;
	    n = num[0] - '0';
		k = num[1] - '0';
		n = n*10;
		return n+k;
	}
}

int helper(string data, int k){
	if(k == 0){
		return 1;
	}
	int s = data.length()-k;

	int result = helper(data,k-1);
	if(k>=2){
		int dig = getInteger(data.substr(s,2));
		if(dig <= 26){
			result += helper(data, k-2);
		}
	}
	return result;

}


int getCodes(string input) {
	int len = input.length();
	return helper(input, len);
}

int main(){
	string str = "121";
	cout<<getCodes(str);
}
