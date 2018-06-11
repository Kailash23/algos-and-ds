#include<iostream>
using namespace std;

int main(){
	int n,space,i,count=0;
	cin>>n;
	space =n;
	for(i=1;i<=n;i++){
		count=i;
		for(int j=1;j<space;j++){
			cout<<" ";
		}
		space--;
		for(int j=1;j<=i;j++){
			cout<<count++;
		}
		cout<<"\n";
	}
}

/*
Input: 5
    1
   23
  345
 4567
56789

*/
