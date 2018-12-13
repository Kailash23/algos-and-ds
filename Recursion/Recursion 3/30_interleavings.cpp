/*
   Interleavings

   Given two strings S (of length m) and T (of length n), you need to find and
   print out all the possible inter leavings that are possible of length (m + n).
   Inter leaving means - all possible combination of characters from both strings
   such that it contain all characters from both strings and, the respective
   ordering of characters of one string should remain same as in original.
   For eg.
   S = ab
   T = cd
   You need to find all strings of length 4 that contain all characters 'a', 'b',
   'c' & 'd'. The only constraint on ordering of characters is - 'a' should always
   come before 'b' and 'c' should always come before 'd'.
   Note : Print all strings in different lines.
 */

#include <iostream>
#include <cstring>
using namespace std;

void interleavingHelper(char* first, char* second, char* output, int len1, int len2, int i, int j, int k) {
	if((i + j) == (len1 + len2)) {
		cout << output << endl;
		return;
	}
	if(i < len1) {
		output[k] = first[i];
		interleavingHelper(first, second, output, len1, len2, i + 1, j, k + 1);
	}
	if(j < len2) {
		output[k] = second[j];
		interleavingHelper(first, second, output, len1, len2, i, j + 1, k + 1);
	}
}


void interleaving(char* first, char* second) {
	int len1 = strlen(first);
	int len2 = strlen(second);
	char *output = new char[len1 + len2 + 1];
	output[len1 + len2] = '\0';
	interleavingHelper(first, second, output, len1, len2, 0, 0, 0);
	delete [] output;
}

int main(){
	char s1[] = "ab";
	char s2[] = "cd";
	interleaving(s1, s2);
}

/*
   abcd
   acbd
   acdb
   cabd
   cadb
   cdab
 */
