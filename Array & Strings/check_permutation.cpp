/*
Given two strings, check if they are permutations of each other. Return true or false.
Permutation means - length of both the strings should same and should contain same set of characters. Order of characters doesn't matter.
*/
#include<iostream>
#include<cstring>
using namespace std;

bool isPermutation(char input1[], char input2[]){
	int k ;
	int sum=0;
	int ascii1 = 0;
	int ascii2 = 0;

	for(int i=0;input1[i]!='\0';i++){
		sum ^= input1[i];
		ascii1 += input1[i];
	}
	for(int i=0;input2[i]!='\0';i++){
		sum ^= input2[i];
		ascii2 += input2[i];
	}

	if(!(sum) && (ascii1 == ascii2)){
		cout<<"true";
	} else {
		cout<<"false";
	}

}

int main(){
	char input1[100] = {"aabb"};
	char input2[100] = {"ccdd"};
	isPermutation(input1,input2);
}
