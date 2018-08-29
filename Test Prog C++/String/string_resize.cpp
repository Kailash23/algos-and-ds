// resizing string
#include <iostream>
#include <string>
using namespace std;

int main (){
	string str ("I like to code in C");
	cout << str << '\n';
	int sz = str.size();
	str.resize (sz+2,'+');
	cout << str << '\n';
	str.resize (14);
	cout << str << '\n';
}
