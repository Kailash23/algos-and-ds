/*
   Check Number

   Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
   Do this recursively.
 */
#include <iostream>
using namespace std;

//1 My approach
bool checkNumber(int input[], int size, int x) {
	if(size == 1) {
		return input[0] == x;
	}
	bool c = checkNumber(input+1, size-1, x);
	return input[0] == x || c;
}

// //2 Coding Ninjas approach
// bool checkNumber(int input[], int size , int x){
//  if(size == 0){
//      return false;
//  }
//  if(input[0] == x){
//      return true;
//  }
//  return checkNumber(input+1, size-1, x);
// }


int main(){
	int arr[] = {2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 5;
	bool ans = checkNumber(arr, n, x);
	ans ? cout<<"Preset.." : cout<<"Not present.."<<endl;
}
