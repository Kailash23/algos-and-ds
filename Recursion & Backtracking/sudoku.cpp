#include <iostream>
using namespace std;

#define SIZE 9

bool checkInCurrentBox(int board[][SIZE], int num, int x, int y){
	int k = x - x%3;
	int l = y - y%3;

	for(int i = k; i < k+3; i++) {
		for(int j = l; j < l+3; j++) {
			if(board[i][j] != 0 && board[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}

bool checkHorizonatalAndVerticle(int board[][SIZE], int num, int x, int y){
	for(int i = 0; i < SIZE; i++) {
		if(board[x][i] == num) {        // If we got cell value equal to num (in coloumn) that means we cant place it.
			return false;
		}
	}

	for(int i = 0; i < SIZE; i++) {
		if(board[i][y] == num) {        // If we got cell value equal to num (in row) that means we cant place it.
			return false;
		}
	}
	return true;
}

bool canNumBeFilled(int board[][SIZE], int num, int x, int y){
	return checkHorizonatalAndVerticle(board,num,x,y) && checkInCurrentBox(board,num,x,y);
}

bool sudokuSolverHelper(int board[][SIZE], int x, int y) {

	if(x == SIZE-1 && y == SIZE-1 && board[x][y] != 0) {     // we reached end ie (8,8) and on a non zero value
		return true;
	}

	if(x < 0 || y < 0 || x >= SIZE || y >= SIZE) {      //invalid situation (out of board situation)
		return false;
	}

	if(board[x][y] == 0) {      // If we got value 0 ie we need to fill it.
		for(int i = 1; i <= SIZE; i++) {        // Looping from 1 to SIZE as we can only fill num from 1 to 9
			if(canNumBeFilled(board,i,x,y)) {       // Checking for num whether it can be placed on that pos or not
				board[x][y] = i;        // Let's place it and then check it can be filled on that place or not
				bool optionWorked = false;      // Make it not working before check

				if(x == SIZE-1 && y == SIZE-1) {        // if we reached end after placing that value ie we are done returning true.
					return true;
				} else if(x == SIZE-1) {        // If we reached the end of the row. we need to go to next coloumn.
					if(sudokuSolverHelper(board,0,y+1)) {
						optionWorked = true;    // we will mark option as true (ie true) cause it gives true for the next cell
					}
				} else {
					if(sudokuSolverHelper(board,x+1,y)) {       // if we didn't reach end of row then move to next cell in that row.
						optionWorked = true;        // we will mark option as true (ie true) cause it gives true for the next cell
					}
				}

				if(!optionWorked) {     //If option not worked then then make it back to zero
					board[x][y] = 0;
				} else {
					return true;        // else if it worked then return true
				}
			}
		}
	} else {        // If we didn't get zero and invalid location
		if(x == SIZE-1) {       // if we reached to the end of row move to next row.
			return sudokuSolverHelper(board, 0, y+1);
		} else {                // else got to next cell in the same row.
			return sudokuSolverHelper(board, x+1, y);
		}
	}
	return false;
}

bool sudokuSolver(int board[][SIZE]){
	bool ans = sudokuSolverHelper(board,0,0);
	if(ans == 1) {
		cout<<"true"<<endl;
	} else {
		cout<<"false"<<endl;
	}
}

int main(){
	int board[SIZE][SIZE] = {
		{9, 0, 0, 0, 2, 0, 7, 5, 0},
		{6, 0, 0, 0, 5, 0, 0, 4, 0},
		{0, 2, 0, 4, 0, 0, 0, 1, 0},
		{2, 0, 8, 0, 0, 0, 0, 0, 0},
		{0, 7, 0, 5, 0, 9, 0, 6, 0},
		{0, 0, 0, 0, 0, 0, 4, 0, 1},
		{0, 1, 0, 0, 0, 5, 0, 8, 0},
		{0, 9, 0, 0, 7, 0, 0, 0, 4},
		{0, 8, 2, 0, 4, 0, 0, 0, 6}
	};
	sudokuSolver(board);
}
