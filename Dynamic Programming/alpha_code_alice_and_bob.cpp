#include <iostream>
#include <vector>
using namespace std;

// int num_codes_dp(int *n, int size, int *arr) {
// 	if(size == 1) {     // Size is one, which means only one code is possible (a-i)
// 		return 1;
// 	}
// 	if(size == 0) {     // Size is zero, which means only one code is possible ie empty string
// 		return 1;
// 	}
// 	if(arr[size] > 0) {     // If work is done already with this size return precomputed value.
// 		return arr[size];
// 	}
//
// 	int output = num_codes_dp(n, size-1, arr);     // Array reduced from back
//
// 	// If we reach here this means we are sure that size is greater than or equal to 2.
//
// 	if((n[size - 2] * 10 + n[size-1]) <= 26) {      // arr[size-2] :- second last digit arr[size-1] :- last digit
// 		output += num_codes_dp(n, size-2, arr);        // Do this if the number formed from second last and last digit of array is greater than 26.
// 	}
// 	cout<<"GG"<<endl;
// 	arr[size] = output;     //Whatever output we get we will store it for further need.
// 	return output;
// }

long num_codes_itr(int *input, int size) {
	long* output = new long[size + 1];
	output[0] = 1;      // Zero length num - one code possible
	output[1] = 1;      // One length num - one code possible

	for(long i = 2; i <= size; i++) {
		output[i] = output[i-1];        //copy value at output[i-1] to output[i] (output[i-1] represents what is the answer for first i-1 digits)
		if(output[i-2] * 10 + output[i-1] <= 26) {
			output[i] += output[i-2];       // We will do this only if last 2 digit combo is less than 26.
		}
	}
	long ans = output[size];     //output[size] contains answer (possible num of codes)
	delete [] output;       // delete output array
	return ans;
}

int main(){
	vector<string> lines;
	string str;
	cin>>str;
	while(str[0]!='0') {
		cin>>str;
		lines.push_back(str);
	}

	for(int i = 0; i < lines.size(); i++) {

		string l = lines[i];
		int size = l.length();
		int *temp = new int[size+1];
		temp = {};

		int *input = new int[size];
		for(int i = 0; i < size; i++) {
			input[i] = l[i]-'0';
		}
		cout<<num_codes_itr(input, size)<<endl;
	}
}
