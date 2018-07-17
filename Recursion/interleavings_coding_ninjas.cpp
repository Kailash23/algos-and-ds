#include<iostream>
#include<cstring>
using namespace std;

void interleavingHelper(char* first, char* second, char*output, int outputIndex = 0){
	if(first[0] == '\0' && second[0] == '\0'){
		output[outputIndex] = '\0';
		cout<<output<<endl;
		return;
	}

	if(first[0] != '\0'){
		output[outputIndex] = first[0];
		interleavingHelper(first+1,second,output,outputIndex+1);
	}

	if(second[0] != '\0'){
		output[outputIndex] = second[0];
		interleavingHelper(first, second+1,output,outputIndex+1);
	}
}


void interleavings(char* first, char* second){
	int m = strlen(first);
	int n = strlen(second);
	char* output = new char[m+n+1];
	interleavingHelper(first,second,output);
	delete [] output;
}

int main(){
	char s1[] = "a";
	char s2[] = "cd";
	interleavings(s1, s2);
}
