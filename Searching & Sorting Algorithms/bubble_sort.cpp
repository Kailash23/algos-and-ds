/*
   Code: Bubble Sort
 */

#include <iostream>
using namespace std;

int bubbleSort(int input[], int n){
	for(int i = 0; i < n - 1; i++){		// n - 1 rounds in bubble sort
	    for(int j = 0; j < n - i - 1; j++){		// Subtracting i because after each round we got largest element shifted to last. No need to compare it anymore.
			if(input[j] > input[j + 1]){
				int temp = input[j + 1];
				input[j + 1] = input[j];
				input[j] = temp;
			}
	    }
	}
}


int main(){
	int input[] = {3,1,6,9,0,4};
	int size = sizeof(input) / sizeof(input[0]);
	bubbleSort(input, size);
	for(int i = 0; i < size; i++) {
		cout << input[i] << " ";
	}
}

/*
   0 1 3 4 6 9
 */

/*
   After 1 round of selection sort smallest element is in its correct location
   But in Bubble sort largest element came to its correct location after 1 round.
   In order to sort an array of n elements we need to have n - 1 rounds.
 */
