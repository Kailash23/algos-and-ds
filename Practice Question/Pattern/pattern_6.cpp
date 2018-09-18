/*
	Arrow pattern

	Print the following pattern for the given number of rows.
	Assume N is always odd.
	Note : There is space after every star.
	Pattern for N = 7
	*
	 * *
	   * * *
	     * * * *
	   * * *
	 * *
	*
*/

#include <iostream>
using namespace std;

void arrow(int n){
	for(int i = 0; i < (n / 2) + 1; i++){
		int space = i;
		while(space > 0){
			cout << " ";
			space--;
		}
	    for(int j = 1; j <= i + 1; j++){
			cout << "* ";
	    }
		cout << endl;
	}

	for(int i = n/2; i > 0; i--){
		int space = i - 1;
		while(space > 0){
			cout<< " ";
			space--;
		}
		for(int j = i; j > 0; j--){
		    cout << "* ";
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	arrow(n);
}

/*
	6
	*
	 * *
	  * * *
	   * * * *
	  * * *
	 * *
	*
*/
