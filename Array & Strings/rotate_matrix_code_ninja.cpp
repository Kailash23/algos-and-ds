/*
   Given an N*N integer square matrix, rotate it by 90 degrees in anti-clockwise direction.
   Try using it without any extra space.
 */
#include <iostream>
using namespace std;

void transpose(int **input, int n){
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			int temp =  input[j][i];
			input[j][i] = input[i][j];
			input[i][j] = temp;
		}
	}
}

void rotate(int **input, int n){
	transpose(input,n);
	for(int j=0; j<n; j++) {
		for(int i=0,k=n-1; i<k; i++,k--) {
			int temp =  input[i][j];
			input[i][j] = input[k][j];
			input[k][j] = temp;
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<input[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int count=0;

	int **array = (int **) malloc (n*sizeof(int*));
	for(int i=0; i<n; i++) {
		array[i] = (int *) malloc(n*sizeof(int));
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			array[i][j]=count++;
		}
	}

	rotate(array,n);

}
