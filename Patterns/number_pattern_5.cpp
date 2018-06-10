#include<iostream>
using namespace std;

int main(){
	int n,space,i;
	cin>>n;
	space = 2*(n-1);
	for(i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<j;
		}
		for(int j=1;j<=space;j++){
			cout<<" ";
		}
		space-=2;
		for(int j=i;j>0;j--){
			cout<<j;
		}

		cout<<endl;
	}
}

/*

*/
