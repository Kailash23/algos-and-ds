#include <cstring>
#include <iostream>
using namespace std;
int main() {
    char input[100];
    cin >> input;
    int len = strlen(input);
    cout << len << endl;
}

//strlen doesn't count '\0' while calculating length of string.
