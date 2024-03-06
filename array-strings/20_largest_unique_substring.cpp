/*
   Given a string S, find the largest substring with no repetition i.e.
   largest substring which contain all unique characters.
 */

#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;

void findLargestUniqueSubstring(char input[], char output[]) {
    unordered_map<char, bool> map;
    int li = 0, temp_li = 0;
    int max_len = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (map.count(input[i]) > 0) {
            if ((i - li) > max_len) {
                max_len = i - li;
                temp_li = li;
            }
            while (map.count(input[i]) > 0) {
                map.erase(input[li++]);
            }
        }
        map[input[i]] = true;
    }
    int ind = 0;
    for (int i = temp_li; i < temp_li + max_len; i++) {
        output[ind++] = input[i];
    }
    output[ind] = '\0';
    cout << output << endl;
}

int main() {
    char input[] = "abcdeaioutu";
    int n = strlen(input);
    char output[n];
    findLargestUniqueSubstring(input, output);
}

/*
   bcdeaiout
 */

/*
    void findLargestUniqueSubstring(char input[], char output[]){
       int n = strlen(input);
       int visited[256] = {0};
       int beg = 0;
       int i, start = 0, end = 0, cur_len = 0, max_len = 0, flag = 1;
       i = start;

       while(i < n) {
           if(flag == 0) {
               i = start;
           }
           if(visited[input[i]] == 0) {
               if(i == n - 1) {
                   flag = 0;
               } else {
                   flag = 1;
               }
               visited[input[i]] = 1;
               cur_len++;
           } else {
               flag = 0;
           }
           if(flag == 0) {
               if(cur_len > max_len) {
                   max_len = cur_len;
                   beg = start;
               }
               start++;
               memset(visited, 0, sizeof(visited));
               cur_len = 0;
           }
 	   	++i;
       }

       int s = 0;
       for(int k = beg; k < beg + max_len; k++) {
           output[s++] = input[k];
       }

       output[s] = '\0';
       cout << output;
    }
 */
