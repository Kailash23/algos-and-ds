/*
   Print all the subsequences of a string.
 */

#include <iostream>
using namespace std;

void subsequencesHelper(string str, string output){
	if(str.size() == 0) {
		cout << output << endl;
		return;
	}
	subsequencesHelper(str.substr(1), output);		// Let's not include the 0th character
	subsequencesHelper(str.substr(1), output + str[0]);		// Let's include the 0th character
}

void subsequences(string str){
	string output;
	subsequencesHelper(str, output);
}

int main(){
	string str = "ab";
	subsequences(str);
}

/*
	    <- (empty string)
	b
    a
    ab
 */

/*
	"input" "output"

					  "ab" ""
					/   	\
				"b" ""      "b" "a"
				/	\		/	  \
			"" ""  "" "b"  "" "a"  "" "ab"
			^
			|
			If input is empty print output
*/
