#include<iostream>
using namespace std;

void find_Ways_Helper(int n, char prev, char prevprev, long long &ans){
	if(n == 1 && prevprev == 'S'){
		ans = 2;
		return;
	}
	if(n == 1){
		ans++;
		return;
	}

	if(prevprev = 'S'){
		find_Ways_Helper(n-1,'W','B', ans);
		find_Ways_Helper(n-1,'R','B', ans);
	} else if(prev == 'B' && prevprev == 'W'){
		find_Ways_Helper(n-1,'R','B', ans);
	} else if(prev == 'B' && prevprev == 'R'){
		find_Ways_Helper(n-1,'W','B', ans);
	} else if(prev == 'W'){
		find_Ways_Helper(n-1,'R','W', ans);
		find_Ways_Helper(n-1,'B','W', ans);
	} else if(prev == 'R'){
		find_Ways_Helper(n-1,'W','R', ans);
		find_Ways_Helper(n-1,'B','R', ans);
	}
}

long long find_Ways(int N){
	long long ans = 0;
	find_Ways_Helper(N,'B','S',ans);
	return ans;
}

int main(){
	int n = 3;
	cout<<find_Ways(n);
}
