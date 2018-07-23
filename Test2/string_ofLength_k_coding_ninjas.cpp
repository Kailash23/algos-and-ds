/*
   Strings of Length k

   Given a string S and an integer k, you need to find and return all the possible strings that can be made of size k using only characters present in string S.
   The characters can repeat as many times as needed.
   Note : The number of output strings can be at max 1000.
 */

#include <iostream>
using namespace std;

int allStrings(char input[], int k, char output[][100]){
	if(k == 0) {
		output[0][0] = '\0';
		return 1;
	}

	char smallOutput[100][100];
	int size = allStrings(input,k-1,smallOutput);

	int row = 0;
	for(int i=0; input[i]!= '\0'; i++) {
		for(int j=0; j<size; j++) {
			int s = 0;
			output[row][s++] = input[i];
			for(int l=0; smallOutput[j][l] != '\0'; l++) {
				output[row][s++] = smallOutput[j][l];
			}
			output[row][s++] = '\0';
			row++;
		}
	}
	return row;
}

int main(){
	char input[] = "abcd";
	int k = 3;
	char output[1000][100];
	int len = allStrings(input, k, output);
	for(int i = 0; i < len; i++) {
		cout<<output[i]<<endl;
	}
}
