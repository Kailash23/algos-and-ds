#include <iostream>
#include <string>

int main() {
    std::string s1, s2;
    s1 = "";
    s2 = "Brownie";
    std::cout << s1.empty() << std::endl;
    std::cout << s2.empty() << std::endl;
}

//Writing s1 = " " will return 0 since s1 stores a whitespace character.
