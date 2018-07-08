#include<iostream>
#include<unordered_map>
using namespace std;

void freq(int arr[], int n){
	unordered_map<int,int> map;
	for(int i=0;i<n;i++){
		map[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		cout<<map[arr[i]]<<" ";
	}
	cout<<endl;
	cout<<map.at(10)<<endl;
	cout<<map[10]<<endl;

}

int main(){
	int arr[] = {1,3,2,4,5,4,3,1,3,4,5,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	freq(arr,n);
}
