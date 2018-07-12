#include<iostream>
using namespace std;


int allIndexes(int input[], int size, int x, int output[]) {

	if(size == 0){
		return 0;
	}

	int pos = allIndexes( input+1, size-1, x , output);

	if(input[0] == x){
		output[1] = output[0];
		output[0] =0;
		return pos+1;
	} else {

	}

}


int main(){
	int arr[] = {2,3,1,4,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int* output = new int[n];
	int x = 5;
	int ans = allIndexes(arr, n , x);
	cout<<ans;
}
