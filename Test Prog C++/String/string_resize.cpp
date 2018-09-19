// resizing string
#include <iostream>
#include <string>
using namespace std;

int main (){
	string str ("I like to code in C");
	cout << str << '\n';

	int len = str.size();
	str.resize (len + 2,'+');
	cout << str << '\n';

	str.resize (14);
	cout << str << '\n';
}

/*
   I like to code in C
   I like to code in C++
   I like to code
 */
