#include<iostream>
#include<cstring>
using namespace std;

void reverseEachWord(char input[]) {
	int start=0,end=0,i=0;
	while((input[i])!='\0'){
	    if(input[i]==' '){
	 	    end = i-1;

	        while(start<end){
				int temp = input[start];
				input[start] = input[end];
				input[end] = temp;
				start++;
				end--;
			}
			start=i+1;
	    }
	    i++;
	}
	end=i-1;
	cout<<start<<" "<<end<<endl;
	while(start<end){
		int temp = input[start];
		input[start] = input[end];
		input[end] = temp;
		start++;
		end--;
	}
}

int main(){
	char str[] = {"Welcome to Coding Ninjas"};
	reverseEachWord(str);
}
