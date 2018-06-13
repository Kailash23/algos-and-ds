#include<iostream>
using namespace std;

void Change(int arr[]){
	arr[2] = 6;
}

int main(){
	int arr[] = {3,2,1};
	Change(arr);
	cout<<arr[2];
}
