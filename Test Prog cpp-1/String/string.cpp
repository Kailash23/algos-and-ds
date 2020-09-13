#include <iostream>
using namespace std;

int main() {
    //1
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;
    cout << *sp << endl;

    // //2
    // string s = "abc";
    // cin>>s;
    // cout<< s <<endl;

    //3
    string str;
    str = "def";
    cout << str << endl;

    //4
    string s1 = "abc";
    getline(cin, s1);
    cout << s1[0] << endl;

    //5
    string s11 = "abs";
    string s22 = "pushups";
    string str1 = s11 + s22; //s+=s1;
    cout << str1 << endl;

    //6
    cout << str1.size() << endl;
    cout << str1.length() << endl;

    //7
    cout << str1.substr(5) << endl; // 2 variation
    cout << str1.substr(5, 2) << endl;

    //8
    cout << str1.find("push");
}
