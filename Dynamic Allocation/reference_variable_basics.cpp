#include<iostream>
using namespace std;

int main(){
	int i = 10;
	int& j = i;		//j is the alias of i (shared same memory)
	i++;
	cout<<j<<endl;	//11
}
