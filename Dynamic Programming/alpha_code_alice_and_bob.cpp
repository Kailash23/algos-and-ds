/*
   Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
   Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down
   to ‘Z’ being assigned 26.”

   Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode
   that in many different ways!”

   Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’,
   ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send
   me the word ‘BEAN’ anyway?”

   Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be
   tons of different decodings and with that many you would find at least two different ones that would make sense.”

   Alice: “How many different decodings?”

   Bob: “Jillions!”
   For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how
   many decodings there can be for a given string using her code.
   Input
   Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits
   representing   a valid encryption (for example, no line will begin with a 0). There will be no spaces
   between the digits. An input   line of ‘0’ will terminate the input and should not be processed.
   Output
   For each input set, output the number of possible decodings for the input string
 */


#include <iostream>
#include <vector>
using namespace std;

/*
	Code is not working properly
 */

// int num_codes_itr(int *input, int size) {
//  int* count = new int[size + 1];
//  count[0] = 1;      // Zero length num - one code possible
//  count[1] = 1;      // One length num - one code possible
//
//  for(int i = 2; i <= size; i++) {
//      count[i] = 0;
//      if(input[i-1] > 0) {        // If the last digit is not 0, then last digit must add to the number of words.
//          count[i] = count[i-1];            //(count[i-1] represents what is the count of possible decodings for first i-1 digits)
//
//      }
//      // If second last digit is smaller than 2 and last digit is
//      // smaller than 7, then last two digits form a valid character
//      if(input[i - 2] == 1 || (input[i-2] == 2 && input[i-1] < 7)) {
//          count[i] += count[i-2];       // We will do this only if last 2 digit combo is less than 26.
//      }
//  }
//
//  int ans = count[size];     //count[size] contains answer (possible num of codes)
//  delete [] count;       // delete count array
//  return ans;
// }

int num_codes_dp(int *input, int size, int *arr) {

	if(size == 1) {     // Size is one, which means only one code is possible (a-i)
		return 1;
	}

	if(size == 0) {     // Size is zero, which means only one code is possible ie empty string
		return 1;
	}

	if(arr[size] > 0) {     // If work is done already with this size return precomputed value.
		return arr[size];
	}

	int count = 0;

	if(input[size-1] > 0) {     // Element at input[size-1] should be greater than zero
		count = num_codes_dp(input, size-1, arr);      // Array reduced from back
	}
	// If we reach here this means we are sure that size is greater than or equal to 2.

	if(input[size - 2] == 1 || (input[size-2] == 2 && input[size-1] < 7)) {      // arr[size-2] :- second last digit arr[size-1] :- last digit
		count += num_codes_dp(input, size-2, arr);        // Do this if the number formed from second last and last digit of array is greater than 26.
	}

	arr[size] = count;     //Whatever count we get we will store it for further need.
	return count;
}

int main(){
	vector<string> lines;
	string str;
	cin>>str;
	lines.push_back(str);


	while(str != "" && str.length() != 1 && str[0] != 0) {
		cin>>str;
		lines.push_back(str);
	}
	vector<string> :: iterator it = lines.end();
	lines.erase(it);

	for(int i = 0; i < lines.size(); i++) {
		string l = lines[i];
		int size = l.length();
		int temp[size+1];
		for(int t = 0; t < size+1; t++) {
			temp[t] = 0;
		}
		int input[size];
		for(int j = 0; j < size; j++) {
			input[j] = l[j]-'0';
		}
		cout<<num_codes_dp(input, size, temp)<<endl;
		//cout<<num_codes_itr(input, size)<<endl;
	}
}
