// another is pass by pointer

#include <iostream>
using namespace std;

void ShowArray(int (*a)[3]){   //  a[][8]
	for(int row = 0; row < 3; ++row) {
		for(int col = 0; col < 3; ++col) {
			cout<<a[row][col]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int map[][3] = {{1,2,3},{4,5,6},{3,5,7}};
	ShowArray(map);
}

/*
   void ShowArray(int (*a)[3])
   is identical to
   void ShowArray(int a[][3])
   The above code sends the ptr to the func, not the values individually .
 */
