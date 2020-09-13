/*
   Replace pi (recursive)

   Given a string, compute recursively a new string where all appearances of
   "pi" have been replaced by "3.14".
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
            temp[ind] = input[i];
            ind++;
        }
        temp[ind] = '\0';
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        int j = 4;
        for (int k = 0; input[k] != '\0'; k++) {
            input[j] = temp[k];
            j++;
        }
        input[j] = '\0';
        replacePi(input + 4);
    } else {
        replacePi(input + 1);
    }
}

int main() {
    char pi[] = "abdpipimnp";
    replacePi(pi);
    cout << pi;
}

/*
   abd3.143.14mnp
 */
