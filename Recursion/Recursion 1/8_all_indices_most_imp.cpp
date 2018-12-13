/*
   All Indices of Number

   Given an array of length N and an integer x, you need to find all the indexes where
   x is present in the input array. Save all the indexes in an array (in increasing order).
   Do this recursively. Indexing in the array starts from 0.
   Sample Input :
   5
   9 8 10 8 8
   8

   Sample Output:
   1 3 4
 */

#include <iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
	if(size == 0) {
		return 0;
	}
	int ans = allIndexes(input, size - 1, x, output);   // removing element from back
	if(input[size - 1] == x) {
		output[ans++] = size - 1;
	}
	return ans;
}

int main(){
	int input[] = {1, 2, 3, 2, 5, 2, 7};
	int n = sizeof(input) / sizeof(input[0]);
	int *output = new int[n];
	int x = 2;
	int size = allIndexes(input, n, x, output);
	for(int i = 0; i < size; i++) {
		cout << output[i] << " ";
	}
}

/*
   1 3 5
 */
 
/*
 #include <bits/stdc++.h>
    using namespace std;

    void findIndexes(int input[], int currIndex, int size, int x, int output[], int &k) {
        if (currIndex == size) return;
        if (input[currIndex] == x) {
            output[k] = currIndex;
            k++;
        }
        findIndexes(input, currIndex + 1, size, x, output, k);
    }

    int allIndexes(int input[], int size, int x, int output[]) {
        int k = 0;
        findIndexes(input, 0, size, x, output, k);
        return k;
    }
 */
