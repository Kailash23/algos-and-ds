#include <iostream>
using namespace std;

void printPattern(int n){
	int count = 1;
	for(int i = n - 1 ; i >= 0; i--){
	    int space = i;
		while(space > 0){
			cout << " ";
			space--;
		}
		for(int j = n; j > i; j--){
		    cout << count++ << " ";
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
	4
	   1
	  2 3
	 4 5 6
	7 8 9 10
 */
