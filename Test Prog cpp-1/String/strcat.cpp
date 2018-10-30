#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char s2[]= "World";
	char s1[20]= "Hello";       //we gave array size to s1 because we are adding the characters of another string to it
	strcat(s1, s2);
	cout << "Source string " << s2 << endl;
	cout << "Target string " << s1 << endl;
	return 0;
}

/*
   Source string World
   Target string HelloWorld
 */
