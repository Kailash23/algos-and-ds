#include<iostream>
using namespace std;

int main() {
	int n, i;
	cin>>n;
	for(i=0; i<n; i+=2){
        for(int j=1;j<=n;j++){
            	cout<<(n*i+j)<<" ";
        }
        cout<<endl;
    }
    if(n%2){
    	i-=2;
    }
    for(i--; i>0; i-=2){
        for(int j=1;j<=n;j++){
            	cout<<(n*i+j)<<" ";
        }
        cout<<endl;
    }
}
