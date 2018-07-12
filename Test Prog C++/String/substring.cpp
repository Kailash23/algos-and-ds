#include <iostream>
#include <string>

int main()
{
	std::string str1 ("I love C++");
	std::cout << str1.substr(3) << std::endl;		//ove C++

	std::string str2 ("I love C++");
	std::cout << str2.substr(3,5) << std::endl;		//ove C

}
