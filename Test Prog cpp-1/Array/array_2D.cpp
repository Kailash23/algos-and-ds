#include <iostream>
using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int arr[m][n];

	int count=0;
	for(int i = 0; i < m; i++){
	    for(int j = 0; j < n; j++){
	        arr[i][j] = count++;
	    }
	}

	for(int i = 0; i < m; i++){
	    for(int j = 0; j < n; j++){
	        cout<<arr[i][j]<<" ";
	    }
	}
}
