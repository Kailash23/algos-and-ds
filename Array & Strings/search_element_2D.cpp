#include<iostream>
using namespace std;

void findElement(int (*arr)[30], int m, int n, int x){
	int i=0,j=n-1;
	cout<<sizeof(arr);
	while (i<m && j>=0) {
		if(arr[i][j]==x){
			cout<<"Found at location: ("<<i<<", "<<j<<")"<<endl;
			return;
		} else if(x > arr[i][j]) {
			i++;
		} else {
			j--;
		}
	}
	cout<<"Not found!";
}

int main(){
	int m,n,k;
	int a[30][30];
	cin>>m;
	cin>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"Element to search: ";
	cin>>k;
	findElement(a,m,n,k);
}
