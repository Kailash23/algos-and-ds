/*
   Program to rotate array left and right.
 */

#include <iostream>
using namespace std;

void rotate_left(int a[], int n){
	if(n > 1) {
		int tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		rotate_left(a + 1, n - 1);
	}
}

void rotate_right(int a[], int n){
	if(n > 1) {
		int tmp = a[n - 1];
		a[n - 1] = a[n - 2];
		a[n - 2] = tmp;
		rotate_right(a, n - 1);
	}
}

void print_array(int arr[], int n){
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {5,6,7,8,9};
	int n  = sizeof(a) / sizeof(a[0]);
	int k  = sizeof(b) / sizeof(b[0]);
	rotate_left(a, n);
	rotate_right(b, k);
	print_array(a, n);
	cout << endl;
	print_array(b, k);
}

/*
   2 3 4 5 1
   9 5 6 7 8
 */
