#include<iostream>
#include<string>
using namespace std;

int main(){
	string str = "Hello";
	int sum = 0;
	int st = 0;
	for(int i=0 ; str[i]!= '\0';i++){
		sum = sum + (str[i]+0);
	}
	cout<<sum;
}
