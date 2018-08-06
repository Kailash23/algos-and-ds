/*
   Code : Rat in a Maze

   Given a maze, NxN matrix. A rat has to find a path from source to destination. maze[0][0] (left top corner) is the source and maze[N-1][N-1](right bottom corner) is destination. There are few cells which are blocked ie 0 in matrix, means rat cannot enter into those cells. Rat can move in any direction ( left, right, up and down).

   You have to check weather rat can reach to destination or not.
 */
#include <iostream>
using namespace std;

bool hasPathHelper(int **input, int n, int** solution, int x, int y) {
	if(x == n-1 && y == n-1) {      //That means we reach the end : return true
		return true;
	}
	//Check for current position
	if(x<0 || y<0 || x>=n || y>=n || input[x][y] == 0 || solution[x][y]==1) {
		return false;       // Invalid location
	}

	solution[x][y] = 1;     //Mark current location as visited

	if(hasPathHelper(input, n, solution, x-1, y)) {
		return true;
	}

	if(hasPathHelper(input, n, solution, x+1, y)) {
		return true;
	}

	if(hasPathHelper(input, n, solution, x, y-1)) {
		return true;
	}

	if(hasPathHelper(input, n, solution, x, y+1)) {
		return true;
	}

	solution[x][y] = 0;     //Path doesn't lead to end so mark it as 0 before returning false.
	return false;
}

bool hasPath(int** arr, int n) {
	int** solution = new int*[n];
	for(int i=0; i<n; i++) {
		solution[i] = new int[n];
		for(int j=0; j<n; j++) {
			solution[i][j] = 0;
		}
	}
	return hasPathHelper(arr,n,solution,0,0);
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
	cout<<hasPath(arr,n)<<endl;
}
