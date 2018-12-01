#include <iostream>
using namespace std;

int main(){
	//1
	char arr[] = "This is a test";
	string str(arr);
	cout << str << endl;        //This is a test

	//2
	string temp;
	temp = arr;
	cout << temp << endl;       //This is a test
}
