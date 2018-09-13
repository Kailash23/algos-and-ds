/*
   Given two strings, check if they are permutations of each other. Return true or false.
   Permutation means - length of both the strings should same and should contain same set of characters. Order of characters doesn't matter.
 */

#include <iostream>
#include <cstring>
using namespace std;

int getAsciiSum(char str[]){
	int sum = 0;
	for(int i=0; i < strlen(str); i++) {
		sum += (int)str[i];
	}
	return sum;
}

bool isPermutation(char input1[], char input2[]){
	if((getAsciiSum(input1) == getAsciiSum(input2)) && (strlen(input1) == strlen(input2))) {
		return true;
	} else {
		return false;
	}
}

int main(){
	char input1[100] = {"aabb"};
	char input2[100] = {"baab"};
	cout<<isPermutation(input1,input2);
}

/*
   1
 */
