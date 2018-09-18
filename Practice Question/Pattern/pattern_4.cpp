/*
	Pattern: Triangle of numbers

	Print the following pattern for the given number of rows.
	Pattern for N = 3

	   1
	  232
	 34543
*/
#include <iostream>
using namespace std;

void printPattern(int n){
	for(int i = 0; i < n; i++){
	    for(int j = n - ( i + 1); j > 0; j--){
	        cout << " ";
	    }
		int temp = i + 1;
		for(int k = 0; k <= i; k++){
			cout << temp++;
		}
		temp -= 2;
		for(int l = 0; l < i; l++){
			cout << temp--;
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	printPattern(n);
}


/*
	5
	    1
	   232
	  34543
	 4567654
	567898765
*/
