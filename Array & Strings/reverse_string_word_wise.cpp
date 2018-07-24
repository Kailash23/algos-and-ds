/*
   Reverse string Word Wise

   Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void reverse(char arr[],int start,int end){
	while(start<end) {
		swap(arr[start],arr[end]);
		start++;
		end--;
	}
}

void reverseStringWordWise(char input[]) {
	int size = strlen(input);
	int start = 0;
	int end = size-1;
	int i=0;
	int j=0;
	int k=0;
	reverse(input,start, end);

	while(input[k]!='\0') {
		if(input[k]==' ') {
			cout<<"k: "<<k<<endl;
			reverse(input,j,k-1);
			j=k+1;
		}
		k++;
	}
	reverse(input,j,size-1);
	cout<<input;

}

int main(){
	char arr[]={"Call me Juggernaut. This is Sparta!"};
	reverseStringWordWise(arr);
}
