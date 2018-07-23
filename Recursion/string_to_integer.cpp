#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int convert(char input[],int size){

	if(strlen(input) == 1) {
		return input[0]-'0';
	}

	int smallOutput = convert(input+1,size-1);
	int firstDigit = input[0]-'0';
	int depth = 1;
	for(int i=0; i<size-1; i++) {
		depth*=10;
	}
	return (firstDigit*depth) + smallOutput;
}

int stringToNumber(char input[]){
	int s = strlen(input);
	return convert(input,s);
}

int main(){
	char arr[] = "27812718";
	int size = strlen(arr);
	int n = stringToNumber(arr);
	cout<<n;
}
