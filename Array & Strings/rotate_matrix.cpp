/*
   Given an N*N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.
   Try using it without any extra space.
 */

#include <iostream>
using namespace std;

void Swap(int& i, int& j){
	int temp = i;
	i = j;
	j = temp;
}

void rotate(int **input, int n){
	int count = 0;
	int level = 0;
	int last = n - 1;
	int totNumOfLevels = n / 2;

	while(level < totNumOfLevels) {

		for(int i = last; i > level; i--) {
			Swap(input[level][i], input[last - i + level][level]);
			Swap(input[level][i], input[last][last - i + level]);
			Swap(input[level][i], input[i][last]);
		}
		++level;
		--last;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){
	int n;
	cin >> n;
	int count = 0;

	int **array = (int **) malloc (n * sizeof(int*));
	for(int i = 0; i < n; i++) {
		array[i] = (int *) malloc(n * sizeof(int));
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			array[i][j] = count++;
		}
	}
	rotate(array,n);
}

/*
   3
   2 5 8
   1 4 7
   0 3 6

 */
