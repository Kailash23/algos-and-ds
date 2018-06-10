#include<iostream>
using namespace std;

int main(){
	int num, n , space, loop,j;
	cin>>n;
	space = n;
	for(loop=1;loop<=n;loop++){
		num = loop;
		for(j=1;j<space;j++){
			cout<<" ";
		}
		space--;

		for(j=1;j<=loop;j++){
			cout<<num;
			num++;
		}
		num-=2;
		for(j=1;j<loop;j++){
			cout<<num;
			num--;
		}
		cout<<"\n";
	}
}
