#include <iostream>
using namespace std;

int main(){
	int m,n;
	cout<<"Rows:";
	cin>>m;
	cout<<"Coloumn:";
	cin>>n;
	int** p = new int*[m];
	for(int i=0; i<m; i++) {
		p[i] = new int[n];
		for(int j=0; j<n; j++) {
			cin>>p[i][j];
		}
	}

	//Displaying 2D-Array
	for(int s=0; s<m; s++) {
		for(int k=0; k<n; k++) {
			cout<<p[s][k]<<" ";
		}
		cout<<endl;
	}

	//Freeing memory
	for(int i=0; i<m; i++) {
		delete [] p[i];
	}
	delete [] p;

}
