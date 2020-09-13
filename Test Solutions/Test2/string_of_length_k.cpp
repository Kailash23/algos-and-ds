/*
   Strings of Length k

   Given a string S and an integer k, you need to find and return all the possible strings that can be made of size k using only characters present in string S.
   The characters can repeat as many times as needed.
   Note : The number of output strings can be at max 1000.
 */

#include <cstring>
#include <iostream>
using namespace std;

int allStringsHelper(char input[], int k, string output[]) {
    if (k == 0) {
        output[0] = "";
        return 1;
    }

    int smallOutputSize = allStringsHelper(input, k - 1, output);

    int inputLen = strlen(input);

    for (int i = 0; i < (inputLen - 1) * smallOutputSize; i++) {
        output[smallOutputSize + i] = output[i % smallOutputSize];
    }

    for (int i = 0; i < inputLen; i++) {
        for (int j = 0; j < smallOutputSize; j++) {
            output[i * smallOutputSize + j] = input[i] + output[i * smallOutputSize + j];
        }
    }
    return smallOutputSize * inputLen;
}

int allStrings(char input[], int k, char output[][100]) {
    string temp[1000];

    int tempSize = allStringsHelper(input, k, temp);

    for (int i = 0; i < tempSize; i++) {
        for (int j = 0; j < k; j++) {
            output[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < tempSize; i++) {
        cout << output[i] << endl;
    }
}

int main() {
    char input[] = "abcd";
    int k = 3;
    char output[1000][100];
    allStrings(input, k, output);
}
