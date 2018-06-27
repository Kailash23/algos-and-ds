#include<iostream>
#include<unordered_map>
using namespace std;

bool subArrayZeroSum(int input[], int n) {
	int sum=0,i;
	int j=0;
	while(j<n){
		 i=j;
		 sum=0;
		while(i<n){
			sum+=input[i];
			if(sum == 0){
				return true;
			}
			i++;
		}
		j++;
	}
	return false;
}

int main(){
	int arr[] = {7,1,3,-4,5,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<subArrayZeroSum(arr, n);

}
