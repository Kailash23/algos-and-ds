/*
   Find smallest substring

   Given two strings string1 and string2 (named large and small), find the smallest
   substring in string1 containing all characters of string2 in O(n). You need to
   return the output substring.
   Note : The characters of string2 need not to be present in same order in string1.
   That is, we need a substring which contains all characters of string2 irrespective
   of the order. Return null if no substring with all characters is present.
 */

#include <iostream>
#include <climits>
using namespace std;
int count =0;
string _findMinSubstringContainingString(string large, string small){
	if(large.size() == 0 || small.size() == 0) {
		return "";
	}

	int map[256]  = {0};

	for(int i = 0; i < small.size(); i++) {
		map[small[i]]+=1;
	}

	int len=0, x, max_len = INT_MAX, present = 0, j=0;
	string str = "";

	for(int i = 0; i < large.size(); i++) {
		if(map[large[i]] > 0) {
			present++;
		}
		map[large[i]]--;
		len++;
		while(map[large[j]] < 0) {
			cout<<++count<<" j "<<j<<endl;
			map[large[j]]++;
			len--;
			j++;
		}
		if(present == small.size() && len < max_len) {
			max_len = i-j+1;
			x=j;
		}
	}

	if(max_len == INT_MAX) {
		return "";
	}

	str = large.substr(x,max_len);
	return str;
}

char* findMinSubstringContainingString(char *large, char *small){
	string str1 = large;
	string str2 = small;
	string result;
	result = _findMinSubstringContainingString(str1,str2);
	int resLength = result.length();
	char *output = new char[resLength + 1];
	int i;
	for(i = 0; i < resLength; i++) {
		output[i] = result[i];
	}
	output[i] = '\0';
	return output;
}


int main(){
	char large[] = "Looks for minimum string";
	char small[] = "mum s";
	findMinSubstringContainingString(large,small);
}

/*
   (0) L
   1 map[large[i]] -1
   2 j 0
   3 len 0
   4 present 0

   (1) o
   5 map[large[i]] -1
   6 j 1
   7 len 0
   8 present 0

   (2) o
   9 map[large[i]] -1
   10 j 2
   11 len 0
   12 present 0

   (3) k
   13 map[large[i]] -1
   14 j 3
   15 len 0
   16 present 0

   (4) s
   17 Present: 1
   18 map[large[i]] 0
   19 len 1
   20 present 1

   (5)
   21 Present: 2
   22 map[large[i]] 0
   23 len 2
   24 present 2

   (6) f
   25 map[large[i]] -1
   26 len 3
   27 present 2

   (7) o
   28 map[large[i]] -1
   29 len 4
   30 present 2

   (8) r
   31 map[large[i]] -1
   32 len 5
   33 present 2

   (9)
   34 map[large[i]] -1
   35 len 6
   36 present 2

   (10) m
   37 Present: 3
   38 map[large[i]] 1
   39 len 7
   40 present 3

   (11) i
   41 map[large[i]] -1
   42 len 8
   43 present 3

   (12) n
   44 map[large[i]] -1
   45 len 9
   46 present 3

   (13) i
   47 map[large[i]] -2
   48 len 10
   49 present 3

   (14) m
   50 Present: 4
   51 map[large[i]] 0
   52 len 11
   53 present 4

   (15) u
   54 Present: 5
   55 map[large[i]] 0
   56 len 12
   57 present 5

   58 maxlen 12
   59 x 4
   (16) m
   60 map[large[i]] -1
   61 len 13
   62 present 5

   (17)
   63 map[large[i]] -2
   64 len 14
   65 present 5

   (18) s
   66 map[large[i]] -1
   67 j 4
   68 j 5
   69 j 6
   70 j 7
   71 j 8
   72 j 9
   73 j 10
   74 j 11
   75 j 12
   76 j 13
   77 len 5
   78 present 5

   79 maxlen 5
   80 x 14
   (19) t
   81 map[large[i]] -1
   82 len 6
   83 present 5

   (20) r
   84 map[large[i]] -1
   85 len 7
   86 present 5

   (21) i
   87 map[large[i]] -1
   88 len 8
   89 present 5

   (22) n
   90 map[large[i]] -1
   91 len 9
   92 present 5

   (23) g
   93 map[large[i]] -1
   94 len 10
   95 present 5
 */
