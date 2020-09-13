/*
   Frequency of word using vector and hash tables
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void findFreq(string str) {
    vector<string> strWords;
    unordered_map<string, int> wordfreq;
    string currentword;
    for (int i = 0; i <= str.length(); i++) {
        if ((str[i] == ' ' || str[i] == '\0') && !currentword.empty()) {
            strWords.push_back(currentword);
            currentword.clear();
        } else {
            currentword += str[i];
        }
    }
    for (int k = 0; k < strWords.size(); k++) {
        wordfreq[strWords[k]]++;
    }
    unordered_map<string, int>::iterator p;
    for (p = wordfreq.begin(); p != wordfreq.end(); p++) {
        cout << "(" << p->first << ", " << p->second << ")\n";
    }
}

int main() {
    string s = "abc abc def def def ghr grh ghr";
    findFreq(s);
}

/*
   (grh, 1)
   (ghr, 2)
   (def, 3)
   (abc, 2)
 */
