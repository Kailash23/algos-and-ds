#include <iostream>
#include <string>
using namespace std;

int main(){
	string str1 ("I love C++");
	cout << str1.substr(3) << std::endl;       //ove C++

	string str2 ("I love C++");
	cout << str2.substr(3,5) << std::endl;     //ove C
}

/*
   ove C++
   ove C
 */
