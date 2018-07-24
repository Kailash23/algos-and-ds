#include <iostream>
using namespace std;

int main(){
	int n,j,k,l,m;
	cin>>n;

	for(int i=0; i<(n/2)+1; i++) {
		for( j=0; j<i; j++) {
			cout<<" ";
		}
		j--;
		for(k=0; k<i+1; k++) {
			cout<<"*";
		}
		k--;
		cout<<endl;
	}
	for(int i=n/2; i>=0; i--) {
		for(l=j-1; l>=0; l--) {
			cout<<" ";
		}
		j--;
		for(m=k-1; m>=0; m--) {
			cout<<"*";
		}
		k--;
		cout<<endl;
	}
}

/*
   Input: 7
 *
 **
 ***
 ****
 ***
 **
 *

 */
