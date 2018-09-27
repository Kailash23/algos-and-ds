/*
   Print all codes - String

   Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a
   numeric string S. Write a program to print the list of all possible codes
   that can be generated from the given string.
   Note : The order of codes are not important. And input string does not
   contain 0s.
 */

#include <iostream>
#include <string>

using namespace std;
/*
void allCodesHelper(string input, string output){
	if(input.size() == 0){
		cout << output << endl;
		return;
	}
	int first = input[0] + '0';
	char firstChar = 'a' + first - 1;
	output += firstChar;
	allCodesHelper(input.substr(1), output);

	if(input[1] != '\0'){
		int second = (first * 10) + (input[1] - '0');
		char secondChar = 'a' + second - 1;
		output += secondChar;
		if(second >= 1 && second <= 26){
			allCodesHelper(input.substr(2), output);
		}
	}
}
*/
int getCodes(string input) {
	string output = "";
	allCodesHelper(input, output);
}

int main(){
	string str = "1123";
	getCodes(str);
}

/*
   aabc
   aau
   akc
   kbc
   ku
 */
