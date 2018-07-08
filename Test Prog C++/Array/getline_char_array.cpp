/*
Use of getline function while dealing with char array.
*/

#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char str[30];
	cout<<"Enter String: ";
	cin.getline(str,30);
	cout<<str;
}
