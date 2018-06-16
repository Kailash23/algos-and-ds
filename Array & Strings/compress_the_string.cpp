#include<iostream>
#include<cstring>
using namespace std;

void stringCompression(char input[]) {
	char k;
	int index=0;
	int len = strlen(input);
	for(int i=0;input[i]!='\0';i++){
		k = input[i];
		input[index++] = input[i];
		int j=i+1;
		char count=49;
		while(input[j]==k){
			count++;
			j++;
			i++;
		}
		if(!(count == 49))
		input[index++]= count;
	}
	input[index]= '\0';
}


int main(){
	char str[] = {"aaabbbccccdddddddeeeegggggk"};
	stringCompression(str);
}
