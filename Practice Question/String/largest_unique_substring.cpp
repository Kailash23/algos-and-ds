/*
   Given a string S, find the largest substring with no repetition i.e.
   largest substring which contain all unique characters.
 */

#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

void findLargestUniqueSubstring(char input[], char output[]){
    unordered_map<char,bool> map;
    int li = 0, temp_li = 0;
    int max_len = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (map.count(input[i]) > 0) {
            if ((i - li) > max_len) {
                max_len = i - li;
                temp_li = li;
            }
            while (map.count(input[i]) > 0)
                map.erase(input[li++]);
        }
        map[input[i]] = true;
    }
    int ind = 0;
    for (int i = temp_li; i < temp_li + max_len; i++) {
        output[ind++] = input[i];
    }
    output[ind] = '\0';
    cout<< output <<endl;
}

int main(){
	char input[]= "abcdeaioutu";
	int n = strlen(input);
	char output[n];
	findLargestUniqueSubstring(input,output);
}

/*
   bcdeaiout
 */
