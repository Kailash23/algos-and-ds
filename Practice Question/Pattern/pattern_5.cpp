/*
   Number Pattern

   Print the following pattern
   Pattern for N = 4
   4 4 4 4 4 4 4
   4 3 3 3 3 3 4
   4 3 2 2 2 3 4
   4 3 2 1 2 3 4
   4 3 2 2 2 3 4
   4 3 3 3 3 3 4
   4 4 4 4 4 4 4
 */

#include <iostream>
using namespace std;

int printPatternHelper(int a, int b, int no, int first, int last){
	if(a == first - 1 || b == last - 1 || a == last - 1 || b == first - 1) {
		return no;
	}
	first++;
	last--;
	no--;
	printPatternHelper(a, b, no, first, last);
}

void printPattern(int n){
	int start, end;
	start = 1;
	end = (2 * n) - 1;
	for(int i = 0; i < end; i++) {
		for(int j = 0; j < end; j++) {
			cout << printPatternHelper(i, j, n, start, end) << " ";
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
   7
   7 7 7 7 7 7 7 7 7 7 7 7 7
   7 6 6 6 6 6 6 6 6 6 6 6 7
   7 6 5 5 5 5 5 5 5 5 5 6 7
   7 6 5 4 4 4 4 4 4 4 5 6 7
   7 6 5 4 3 3 3 3 3 4 5 6 7
   7 6 5 4 3 2 2 2 3 4 5 6 7
   7 6 5 4 3 2 1 2 3 4 5 6 7
   7 6 5 4 3 2 2 2 3 4 5 6 7
   7 6 5 4 3 3 3 3 3 4 5 6 7
   7 6 5 4 4 4 4 4 4 4 5 6 7
   7 6 5 5 5 5 5 5 5 5 5 6 7
   7 6 6 6 6 6 6 6 6 6 6 6 7
   7 7 7 7 7 7 7 7 7 7 7 7 7
 */
