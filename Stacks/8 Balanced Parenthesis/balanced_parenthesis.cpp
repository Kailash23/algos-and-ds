/*
   Code : Balanced Parenthesis

   Given a string expression, check if brackets present in the expression are balanced
   or not. Brackets are balanced if the bracket which opens last, closes first.
   You need to return true if it is balanced, false otherwise.
 */
#include <iostream>
using namespace std;

#include <cstring>
#include <stack>

bool checkBalanced(char *expn) {
    stack<char> s;
    int len = strlen(expn);
    for (int i = 0; i < len; i++) {
        if (expn[i] == '(' || expn[i] == '{' || expn[i] == '[') {
            s.push(expn[i]);
        } else if (expn[i] == ')' || expn[i] == '}' || expn[i] == ']') {
            if (s.empty()) {
                return false;
            }
            char ch = s.top();
            s.pop();
            if (expn[i] == ')' && ch == '(') {
                continue;
            } else if (expn[i] == '}' && ch == '{') {
                continue;
            } else if (expn[i] == ']' && ch == '[') {
                continue;
            } else {
                return false;
            }
        }
    }
    if (s.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char expn[] = "{a+[b+(c+d)]+(e+f)}";
    if (checkBalanced(expn)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

/*
   True
 */
