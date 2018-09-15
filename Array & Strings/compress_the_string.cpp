/*
   Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
   For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
 */
#include <iostream>
#include <cstring>
using namespace std;

void stringCompression(char input[]) {
	char k;
	int index = 0;
	int len = strlen(input);
	for(int i = 0; input[i] != '\0'; i++) {
		k = input[i];
		input[index++] = input[i];
		int j = i + 1;
		char count = 49;
		while(input[j] == k) {
			count++;
			j++;
			i++;
		}
		if(!(count == 49))
			input[index++] = count;
	}
	input[index] = '\0';
	cout << input << endl;
}


int main(){
	char str[] = {"aaabbbccccdddddddeeeegggggk"};
	stringCompression(str);
}

/*
   a3b3c4d7e4g5k
 */
