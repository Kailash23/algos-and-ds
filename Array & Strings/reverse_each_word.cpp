/*
   Given a string S, reverse each word of a string individually.
   For eg. if a string is "abc def", reversed string should be "cba fed".
 */

#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char input[]) {
	int start = 0, end = 0;
	int len = strlen(input);
	for(int i = 0; i <= len; i++) {
		if(input[i] == ' ' || input[i] == '\0') {
			end = i - 1;
			while(start < end) {
				swap(input[start], input[end]);
				start++;
				end--;
			}
			start = i + 1;
		}
	}
	cout<< input <<endl;
}

int main(){
	char str[] = {"Welcome to Coding Ninjas"};
	reverseEachWord(str);
}

/*
   emocleW ot gnidoC sajniN
 */

/*
	swap(input[start], input[end]);		// Defined in iostream
			OR
	int temp = input[start];
	input[start] = input[end];
	input[end] = temp;
*/
