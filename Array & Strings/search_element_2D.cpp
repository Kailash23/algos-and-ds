/*
   We have given a 2D array which is sorted row-wise and coloumn-wise.
   You have to find an element in that matrix.
 */

#include <iostream>
using namespace std;

void findElement(int (*arr)[30], int row, int col, int x){
	int i = 0, j = col - 1;
	while (i < row && j >= 0) {
		if(arr[i][j] == x) {
			cout << "Found at location: (" << i << ", " << j << ")" << endl;
			return;
		} else if(x > arr[i][j]) {
			i++;
		} else {
			j--;
		}
	}
	cout << "Not found!";
}

int main(){
	int m,n,k;
	int a[30][30];
	cin >> m;
	cin >> n;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << "Element to search: ";
	cin >> k;
	findElement(a, m, n, k);
}

/*
   First Approach -
    Traverse each element one by one and find that number. - Time:O(m*n)

   Second Approach -
    Apply binary search at each row or coloumn. Time: O(mlog(n)) - row
                                                        OR
                                                      O(nlog(n)) - coloumn

   Third Approach -
    Go to top right corner (0,col-1). If x is greater than that number move down ie increment x,
    ie movw down in another row. If x is left is less than that number move left in the same
    coloumn.
 */

/*
   5 4
   5 7 8 20
   9 11 13 30
   10 20 29 40
   15 23 30 50
   18 25 33 60
   Element to search: 33
   Found at location: (4, 2)
 */
