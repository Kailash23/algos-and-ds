#include <iostream>
#include <string>
using namespace std;

void printIncreasingNumbersHelper(int n, string output, int start){

	if(n == 0) {
		cout<<output<<endl;
		return;
	}

	for(int i = start; i < 10; i++) {
		string a = to_string(i);
		printIncreasingNumbersHelper(n-1,output+a,i+1);
	}

}

void printIncreasingNumbers(int n) {
	string output;
	int start = 1;
	printIncreasingNumbersHelper(n, output, start);
}


int main(){
	int n = 3;
	printIncreasingNumbers(n);
}
