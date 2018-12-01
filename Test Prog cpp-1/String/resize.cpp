#include <iostream>
#include <string>

int main(){
	std::string s = "I love C";
	int size = s.size();             //  size of s
	s.resize(size + 2, '+');         //  resizing s
	std::cout << s << std::endl;
}


/*
   resize() function resizes our string to a specified length.
   Suppose, the specified length is 5. If the specified length
   (i.e. 5 ) is smaller than the current length ( suppose 7 ),
   then the string will contain only the first 5 characters.
 */
