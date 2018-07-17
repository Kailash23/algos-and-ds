#include<iostream>
#include<cstring>
using namespace std;

void interleavingHelper(char* first, char* second, char* output, int len1, int len2, int i, int j, int k) {
	if((i+j) == (len1+len2)){
		cout<<output<<endl;
		return;
	}

	if(i<len1){
		output[k] = first[i];
		interleavingHelper(first,second,output,len1,len2,i+1,j,k+1);
	}
	if(j<len2){
		output[k] = second[j];
		interleavingHelper(first,second,output,len1,len2,i,j+1,k+1);
	}
}


void interleaving(char* first, char* second) {
	int len1 = strlen(first);
	int len2 = strlen(second);
	char *output = new char[len1+len2+1];
	output[len1+len2] = '\0';
	interleavingHelper(first, second, output, len1, len2, 0, 0, 0);
	delete [] output;
}

int main(){
	char s1[] = "ab";
	char s2[] = "cd";
	interleaving(s1, s2);
}
