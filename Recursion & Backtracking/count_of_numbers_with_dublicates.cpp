/*
   Code : No. of numbers - with duplicates

   Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

long num(int* input, int n, int* fact, int* freq, int deno) {

	if(n == 0 || n == 1) {      // If sigle or zero digit no retrun 0
		return 0;
	}

	long ans = 0;

	for(int i = input[0]+1; i < 10; i++) {      //start from number greater then first digit to 10
		if(freq[i] > 0) {       //Check wether that digit is present or not.
			int s = (fact[n-1] / deno) * freq[i];     // Divide deno which present product of factorial of each digit's freq.
			ans += s;    // Multiply by freq of num which is in left most side.
		}
	}

	deno = deno / freq[input[0]];       // Divide deno by freq of left most side digit cause recursion is going to call in the rest digits, which didn't have that num.
	freq[input[0]]--;       // Decreasing the freq of the left most digit by one, as this will not needed in subsequent recursion call.
	ans += num(input+1, n-1, fact, freq, deno);
	return ans;
}

void convertToArrayOfInt(string s, int arr[], int len){
	int i = 0;
	for( i = 0; i < len; i++) {
		arr[i] = s[i] - '0';
	}
}

string covertToString(long n, string s) {       // Recursive funtion to convert long to string
	if(n == 0) {
		return s;
	}
	int k = n % 10;     // This will get digit at one's place
	string a = to_string(k);        // to_string will convert integer to string
	n = n / 10;         // making smaller input for the recursion (div by 10)
	return covertToString(n, s) + a;
}

long numberOfNumbersWithDuplicates(long n){
	string str = "";
	string s = covertToString(n,str);
	int len = s.length();
	int *arr = new int[len];

	convertToArrayOfInt(s,arr,len);

	int *fact = new int[len+1];     // Optimization we are passing pre computed factorial array.
	fact[0] = 1;
	int freq[10] = {};      // This will set all element to 0.

	for(int i = 0; i < len; i++) {
		freq[arr[i]]++;
		fact[i+1] = (i+1) * fact[i];        // Calculating factorial from previous value
	}


	int deno = 1;
	for(int i = 0; i < 9; i++) {      //Calculating denominator (needed cause we have repeated digits)
		if(freq[i] > 0) {
			deno *= fact[freq[i]];      // product of factorial of freq of each repeated digits in the number
		}
	}
	return num(arr, len, fact, freq,deno);
}

int main(){
	long n;
	cin>>n;
	long ans = numberOfNumbersWithDuplicates(n);
	cout<<ans<<endl;
}
