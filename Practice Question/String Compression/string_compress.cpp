#include <iostream>
#include <cstring>
using namespace std;

void stringCompression(char input[]) {
	int ind = 0;
	char ch;
	int count = 0;
	for(int i = 0; input[i] != '\0'; i++) {
		ch = input[i];
		input[ind++] = ch;
		while(ch == input[i]){
			count++;
			i++;
		}
		i--;
		if(!(count == 1)){
			input[ind++] = '0' + count;
		}
		count = 0;
	}
	input[ind] = '\0';
	cout<< input <<endl;
}

int main(){
	char str[] = {"aaabbbccccdddddddeeeegggggk"};
	stringCompression(str);
}
