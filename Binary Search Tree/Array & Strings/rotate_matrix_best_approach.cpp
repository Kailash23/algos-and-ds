/*
   Given an N*N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.
   Try using it without any extra space.
 */

#include <iostream>
using namespace std;

void transpose(int **input, int n){
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			swap(input[i][j], input[j][i]);
		}
	}
}

void printMatrix(int **input, int n){
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}

void rotate(int **input, int n){
	transpose(input, n);
	for(int i = 0; i < n; i++) {
		for(int j = 0, k = n - 1; j < k; j++, k--) {
			swap(input[j][i], input[k][i]);
		}
	}
	printMatrix(input, n);
}

int main(){
	int n;
	cin >> n;
	int count = 1;

	int **array = new int*[n];      // Declaring 2D array
	for(int i = 0; i < n; i++) {
		array[i] = new int[n];
	}

	for(int i = 0; i < n; i++) {        // Taking input using count
		for(int j = 0; j < n; j++) {
			array[i][j] = count++;
		}
	}
	rotate(array, n);
}

/*
   C++ Lang

   int **array = new int*[row];
   for(int i = 0;i < row; i++){
        array[i] = new int[col];
   }

   C Lang

   int **array = (int**) malloc (row * sizeof(int*));
   for(int i = 0; i < row; i++) {
        array[i] = (int *) malloc(col * sizeof(int));
   }
 */

/*
   4
   4 8 12 16
   3 7 11 15
   2 6 10 14
   1 5 9 13
 */
