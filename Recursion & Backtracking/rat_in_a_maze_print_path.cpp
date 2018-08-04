#include <iostream>
using namespace std;

void printPathHelper(int** input, int n, int** solution, int x, int y) {
	if(x == n-1 && y == n-1) {
		solution[x][y] = 1;
		cout<<endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout<<solution[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}

	if(x < 0 || y < 0 || x>=n || y>=n || input[x][y] == 0 || solution[x][y] == 1) {
		return;
	}

	solution[x][y] = 1;

	printPathHelper(input, n, solution, x-1, y);
	printPathHelper(input, n, solution, x, y-1);
	printPathHelper(input, n, solution, x+1, y);
	printPathHelper(input, n, solution, x, y+1);

	solution[x][y] = 0;
}

void hasPath(int** arr, int n) {
	int** solution = new int*[n];
	for(int i=0; i<n; i++) {
		solution[i] = new int[n];
		for(int j=0; j<n; j++) {
			solution[i][j] = 0;
		}
	}
	printPathHelper(arr,n,solution,0,0);
}

int main(){
	int **arr;
	int n;
	cin>>n;
	arr = new int*[n];
	for(int i=0; i<n; i++) {
		arr[i] = new int[n];
		for(int j=0; j<n; j++) {
			cin>>arr[i][j];
		}
	}
	hasPath(arr,n);
}

/*
   3
   1 1 0 1 1 0 1 1 1

   1 0 0
   1 0 0
   1 1 1


   1 0 0
   1 1 0
   0 1 1


   1 1 0
   1 1 0
   1 1 1


   1 1 0
   0 1 0
   0 1 1

 */
