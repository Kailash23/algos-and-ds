#include <iostream>
using namespace std;

int main() {
    string str = "Not Unique";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    cout << str << endl;
}
