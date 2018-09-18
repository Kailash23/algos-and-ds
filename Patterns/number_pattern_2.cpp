#include <iostream>
using namespace std;

int PrintPattern(int a, int b, int no, int last, int first ){

	if(a == first || b == last || a == last || b == first) {
		return no;
	}
	first++;
	last--;
	no--;
	PrintPattern(a, b, no, last, first);

}

int main(){
	int num,n,start,end;
	cin >> num;
	start = 1;
	end = (2 * num) - 1;
	for(int i = 1; i <= end; i++) {
		for(int j = 1; j <= end; j++) {
			cout << PrintPattern(i, j, num, end, start) << " ";
		}
		cout << endl;
	}
}

/*
   Input: 5
   5 5 5 5 5 5 5 5 5
   5 4 4 4 4 4 4 4 5
   5 4 3 3 3 3 3 4 5
   5 4 3 2 2 2 3 4 5
   5 4 3 2 1 2 3 4 5
   5 4 3 2 2 2 3 4 5
   5 4 3 3 3 3 3 4 5
   5 4 4 4 4 4 4 4 5
   5 5 5 5 5 5 5 5 5
 */
