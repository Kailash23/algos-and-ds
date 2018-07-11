#include<iostream>
using namespace std;


int allIndexes(int input[], int size, int x, int output[]) {
	if(size == 0){
		return 0;
	}
	int pos = allIndexes(input+1,size-1,x,output);

}


int main(){
	int arr[] = {1,5,4,5,6,4,3,4,5,6,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int output[] = new
	int x = 5;
	int ans = allIndexes(arr, n , x);
	cout<<ans;
}
