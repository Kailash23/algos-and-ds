#include <iostream>
#include <string>

int main()
{
	std::string str1 ("I love C++");
	std::cout << str1.find('l') << std::endl;       //2

	std::string str3 ("I love C++");
	std::string str4 ("C++");
	std::cout << str3.find(str4) << std::endl;      //7
}


//find() function finds the position of the first occurrence of a character or string in a string
