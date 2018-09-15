/*
   Given a two dimensional n*m array, print the array in a sine wave order. i.e.
   print the first column top to bottom, next column bottom to top and so on.
 */

#include <iostream>
using namespace std;

void wavePrint(int input[][500], int row, int col){
	for(int i = 0 ; i < col ; i++){
		if(i % 2 == 0){
			int j = 0;
			while(j < row){
				cout << input[j][i] << " ";
				j++;
			}
		} else {
			int j = row - 1;
			while(j >= 0){
				cout << input[j][i] << " ";
				j--;
			}
		}
	}
}

int main(){
	int arr[500][500];
	int m, n;
	cin >> m >> n;
	int count = 1;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			arr[i][j] = count++;
		}
	}
	wavePrint(arr, m, n);
}

/*
   1 2 3
   4 5 6
   7 8 9

	3 3
	1 4 7 8 5 2 3 6 9
 */

/*
   00 01 02
   10 11 12
   20 21 22
 */
