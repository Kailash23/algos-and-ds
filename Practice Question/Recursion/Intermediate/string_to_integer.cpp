/*
   String to Integer

   Write a recursive function to convert a given string into the number it
   represents. That is input will be a numeric string that contains only
   numbers, you need to convert the string into corresponding integer and
   return the answer.
 */

#include <iostream>
#include <cstring>
using namespace std;

int stringToNumberHelper(char input[], int len){
	if(len == 0){
		return 0;
	}
	int smallNum = input[len - 1]  - '0';
	int ans = stringToNumberHelper(input, len - 1);
	return ans * 10 + smallNum;
}

int stringToNumber(char input[]) {
	return stringToNumberHelper(input, strlen(input));
}

int main(){
	char input[] = "1234";
	cout << stringToNumber(input);
}
