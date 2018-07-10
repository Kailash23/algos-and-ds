#include<iostream>
using namespace std;

int sum(int a[], int size, int si = 0){		//Default value is given to right most field only
	int ans = 0;
	for(int i=si;i<size;i++){
		ans += a[i];
	}
	return ans;
}

int sum2(int a=0, int b=0, int c=0, int d=0){		//we can specify all as default value
	return a+b+c+d;
}

int main(){
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<sum(a,n)<<endl;		//15
	cout<<sum(a,n,3)<<endl;		//9

	cout<<sum2(2,3)<<endl;		//5
	cout<<sum2(2,3,4)<<endl;		//9
	cout<<sum2()<<endl;		//0
}
