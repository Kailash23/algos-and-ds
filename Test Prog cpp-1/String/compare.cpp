#include <iostream>
#include <string>

int main() {
    std::string str1("have apple");
    std::string str2("zhave app");
    std::cout << str1.compare(str2) << std::endl; //-1

    std::string str3("have apple");
    std::string str4("have app");
    std::cout << str3.compare(str4) << std::endl; //2

    std::string str5("have gpple");
    std::string str6("have apple");
    std::cout << str5.compare(str6) << std::endl; //1

    std::string str7("have app");
    std::string str8("have apple");
    std::cout << str7.compare(str8) << std::endl; //-2

    return 0;
}

/*
   compare() function compares the value of a string ( str1 ) with another string ( str2 ).
   It returns 0 if both the strings are equal.
   It returns a positive value if either str1 > str2 or the first unmatched letter of str1 is greater than that of str2.
   It returns a negative value if either str1 < str2 or the first unmatched letter of str1 is less than that of str2.
 */
