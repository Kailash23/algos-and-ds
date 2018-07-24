#include <iostream>
using namespace std;

int main(){
	char str[] = {"abc"};
	char chr[] = {"abc"};
	int k;
	int sum=0;
	for(int i=0; str[i]!='\0'; i++) {
		k = str[i];
		sum ^= str[i];
	}
	for(int i=0; chr[i]!='\0'; i++) {
		k = chr[i];
		sum ^= chr[i];
	}
	cout<<sum;
}
