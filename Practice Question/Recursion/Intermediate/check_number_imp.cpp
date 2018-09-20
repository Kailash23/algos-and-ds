/*
   Check Number

   Given an array of length N and an integer x, you need to find if x is present in
   the array or not. Return true or false.
   Do this recursively.
 */

#include <iostream>
using namespace std;

bool checkNumber(int input[], int size, int x) {
	if(size == 0){
		return 0;
	}
	if(input[0] == x){
		return true;
	}
	return checkNumber(input + 1, size -1, x);
}

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 4;
	if(checkNumber(arr, n, x)){
		cout << "Found";
	} else {
		cout << "Not Found";
	}
}

/*
	bool checkNumber(int input[], int size, int x) {
		if(size == 1){
			return input[0] == x;
		}
		bool smallAns;
		if(input[0] == x){
			smallAns = true;
		} else {
			smallAns = false;
		}
		return smallAns || checkNumber(input + 1, size - 1, x);
	}
*/
