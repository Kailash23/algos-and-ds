#include <iostream>
using namespace std;

int main(){
	string str = "1234";
	int a = str[0] - '0';
	cout << a << endl;      // 1

	char ch = 'a';
	ch = ch + a;
	cout << ch << endl;     // b

	// if a->1, b->2, c->3, c->4...

	char chr = 'a' + (3 - 1);
	cout << chr << endl;        // c
}

/*
   1
   b
   c
 */
