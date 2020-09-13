/*
   Replace pi (recursive)

   Given a string, compute recursively a new string where all appearances of "pi"
   have been replaced by "3.14"
 */

#include <cstring>
#include <iostream>
using namespace std;

void replacePi(char input[]) {
    if (input[0] == '\0') {
        return;
    }
    if (input[0] == 'p' && input[1] == 'i') {
        char *temp = new char[strlen(input) - 2];
        int ind = 0;
        for (int i = 2; input[i] != '\0'; i++) {
            temp[ind++] = input[i];
        }
        temp[ind] = '\0';
        ind = 0;
        input[ind++] = '3';
        input[ind++] = '.';
        input[ind++] = '1';
        input[ind++] = '4';
        for (int i = 0; input[i] != '\0'; i++) {
            input[ind++] = temp[i];
        }
        replacePi(input + 4);
    } else {
        replacePi(input + 1);
    }
}

int main() {
    char str[] = "piwdiepi";
    replacePi(str);
    cout << str << endl;
}

/*
   3.14wdie3.14
 */
