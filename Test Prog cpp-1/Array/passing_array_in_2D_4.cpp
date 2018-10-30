
#include <iostream>
using namespace std;

void ShowArray(int *ptr, int x, int y) {
	for(int row=0; row<x; ++row) {
		for(int col=0; col<y; ++col) {
			cout<<ptr[row * y + col]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int map[][3] = {{1,2,3},{4,5,6},{3,5,7},{3,2,4}};
	ShowArray(&map[0][0],4,3);
}
