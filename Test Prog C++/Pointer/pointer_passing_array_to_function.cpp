#include<iostream>
using namespace std;

int sum(int *a,int size){
	cout<<sizeof(a)<<endl;		//4
	int ans = 0;
	for(int i=0;i<size;i++){
		ans += a[i];
	}
	return ans;
}

int main(){
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	cout<<sizeof(a)<<endl;		//40
	cout<<sum(a,10)<<endl;		//45
	cout<<sum(a+3,7)<<endl;		//42
}
