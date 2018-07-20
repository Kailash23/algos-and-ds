#include<iostream>
#include<string>

using namespace std;

void helper(string data, int k, string output){
	if(k == 0){
		cout<<output<<endl;
		return;
	}

	int s = data.length() - k;

	int first = data[s] - '0';
	char firstChar = first + 'a' -1;
	output += firstChar;

	helper(data,k-1,output);

	if(k>=2){
		int second = (first * 10) + (data[1] - '0');
		if(second <= 26){

			int l = output.length();
			output = output.substr(0,l-1);

			char secondChar = second + 'a' - 1;
			output += secondChar;
		    helper(data, k-2, output);
		}
	}
}


int getCodes(string input) {
	int len = input.length();
	string output = "";
    helper(input, len, output);
}

int main(){
	string str = "1123";
	getCodes(str);
}
