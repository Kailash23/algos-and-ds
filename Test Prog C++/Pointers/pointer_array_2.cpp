#include<iostream>
using namespace std;

int main(){
	char str[] = "abc";
	int i=0;
	cout<<str[i]<<endl;		//a
	cout<<*(str)+i<<endl;		//97
	cout<<*(i+str)<<endl;		//a
	cout<<i[str]<<endl;		//a
}
