
/*
   Loot Houses

   A thief wants to loot houses. He knows the amount of money in each house. He cannot
   loot two consecutive houses. Find the maximum amount of money he can loot.
 */
#include <iostream>
using namespace std;

int getMaxMoney(int arr[], int n){

	if(n == 0) {        // No house to loot means he can't loot anything ie 0
		return 0;
	}

	if(n == 1) {        // If only one house to loot
		return arr[0];
	}

	if(n == 2) {        // If only two house to loot we will loot max one
		return max(arr[0], arr[1]);
	}

	int *loot = new int[n];
	loot[0] = arr[0];       // only first house loot will be stored
	loot[1] = max(arr[0], arr[1]);      // we got 2 house (arr[0] & arr[1]) we will loot max

	for(int i = 2; i < n; i++) {     // for house 3 to n-1 house.
		int s = loot[i-2] + arr[i];
		loot[i] = max(s,loot[i-1]);
	}
	return loot[n-1];
}


int main(){
	int arr[] = {2,4,5,8,7,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<getMaxMoney(arr, size);
}
