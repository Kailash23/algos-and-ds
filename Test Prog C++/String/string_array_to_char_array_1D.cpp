/*
   CPP program to convert string to char array.
 */
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	string s = "Juggernaut";
	int n = s.length();

	char char_array[n+1];       // declaring character array

	// copying the contents of the
	// string to char array
	strcpy(char_array, s.c_str());

	for (int i=0; i<n; i++) {
		cout << char_array[i];
	}
	return 0;
}
