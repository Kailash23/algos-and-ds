#include<iostream>
#include<string>
using namespace std;

int getCodes(string input, string output[10000]) {
	if(input.length() == 1){
		output[0] = (char)(((int)input[0])+48);
		return 1;
	}

}

int main(){
	string str = "1123";
	string out[10000];
	getCodes(str,out);
}
