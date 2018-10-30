/*
   program to convert string to char array.
 */

#include <cstring>
#include <iostream>

using namespace std;

int main(){
	string s = "Juggernaut";
	int n = s.length();
	char *char_array = new char[n + 1];       // declaring character array
	// copying the contents of the
	// string to char array
	strcpy(char_array, s.c_str());
	cout << char_array << endl;
	return 0;
}
