#include <iostream>
#include <vector>
using namespace std;

void splitword(string str) {
    vector<string> strWords; //vector (dynamic array)
    string currentWord;

    for (int i = 0; i <= str.length(); i++) {
        if ((str[i] == ' ' || str[i] == '\0') && !currentWord.empty()) {
            strWords.push_back(currentWord);
            currentWord.clear();
        } else {
            currentWord += str[i];
        }
    }
    for (int k = 0; k < strWords.size(); k++) {
        cout << strWords[k] << endl;
    }
}

int main() {
    string s = {"You have summoned Juggernaut!"};
    splitword(s);
}

/*
   You
   have
   summoned
   Juggernaut!
 */
