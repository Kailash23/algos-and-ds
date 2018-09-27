/*
   Code : Compress the string

   Write a program to do basic string compression. For a character which is
   consecutively repeated more than once, replace consecutive duplicate occurrences
   with the count of repetitions.
   For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
   Note : Consecutive count of every character in input string is less than equal
   to 9.
 */

#include <iostream>
#include <cstring>
using namespace std;

void stringCompression(char input[]) {
	int ind = 0;
	char ch;
	int count = 0;
	for(int i = 0; input[i] != '\0'; i++) {
		ch = input[i];
		input[ind++] = ch;
		while(ch == input[i]) {
			count++;
			i++;
		}
		i--;
		if(!(count == 1)) {
			input[ind++] = '0' + count;
		}
		count = 0;
	}
	input[ind] = '\0';
	cout<< input <<endl;
}

int main(){
	char str[] = {"aaabbbccccdddddddeeeegggggk"};
	stringCompression(str);
}

/*
   a3b3c4d7e4g5k
 */
