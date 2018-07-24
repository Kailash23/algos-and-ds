#include <iostream>
using namespace std;

void printPattern(int n){
	for(int i = 0; i < 2*n-1; i++) {
		int flag = 1, flag1 = 0;
		int x = n;
		for(int j=0; j<2*n-1; j++) {
			if(i==j || i+j == 2*n-2) {
				flag ^= 1;
				if(i == j && i+j == 2*n-2) {
					flag ^= 1;
				}
				if(flag) {
					flag1 = 1;
				}
			}
			cout<<x<<" ";
			if(flag) {
				if(flag1) {
					x++;
				} else {
					x--;
				}
			}
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	printPattern(n);
}

/*
   Input:5
   5 5 5 5 5 5 5 5 5
   5 4 4 4 4 4 4 4 5
   5 4 3 3 3 3 3 4 5
   5 4 3 2 2 2 3 4 5
   5 4 3 2 1 2 3 4 5
   5 4 3 2 2 2 3 4 5
   5 4 3 3 3 3 3 4 5
   5 4 4 4 4 4 4 4 5
   5 5 5 5 5 5 5 5 5

 */
