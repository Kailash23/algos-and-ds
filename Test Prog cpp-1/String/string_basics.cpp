#include <iostream>
using namespace std;

int main() {
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;  //0x756ca0
    cout << *sp << endl; //def

    string str2;
    getline(cin, str2);
    cout << str2 << endl; //xyz

    string s = "abc";
    s += str2;
    cout << s << endl;

    cout << s.size() << endl;
    cout << s.length() << endl;

    string str1 = "abcdefgh";
    cout << str1.substr(3) << endl;    //defgh
    cout << str1.substr(3, 3) << endl; //def

    cout << str1.find("def") << endl; //3
}

/*
   0x1016da8
   def
   xyz
   xyz
   abcxyz
   6
   6
   defgh
   def
   3

 */
