/*
   String to Integer

   Write a recursive function to convert a given string into the number it
   represents. That is input will be a numeric string that contains only numbers,
   you need to convert the string into corresponding integer and return the answer.
 */

#include <iostream>
#include <cstring>
using namespace std;

int stringToNumber(char input[], int last){     //Worked on last index
	if(last == 0) {
		return input[last] - '0';
	}
	int smallAns = stringToNumber(input, last - 1);
	int a = input[last] - '0';
	return smallAns * 10 + a;
}

int convert(char input[]){
	int len = strlen(input);
	return stringToNumber(input, len - 1);
}

int main(){
	char arr[] = "12354";
	cout << convert(arr);
}

/*
   12354
 */
