#include <iostream>
using namespace std;

void printAllPrefixes(char input[]){
	for(int i = 0; input[i] != '\0'; i++) {
		for(int j = 0; j <= i ; j++) {
			cout << input[j];
		}
		cout << endl;
	}
}

int main(){
	char input[] = {"abcd"};
	printAllPrefixes(input);
}

/*
   a
   ab
   abc
   abcd
 */
