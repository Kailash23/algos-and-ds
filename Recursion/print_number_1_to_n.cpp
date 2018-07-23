/*
   Print Numbers

   Given the code to print number from 1 to n in increasing order recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass
 */

#include <iostream>
using namespace std;
//1
void print(int n){
	if(n == 1) {
		cout<<"1 ";
		return;
	}
	print(n-1);
	cout<<n<<" ";
}

//2
// void print(int n){
//     if(n == 1){
//         cout << n << " ";
//         return;
//     }
//     print(n - 1);
//     cout << n << " ";
// }

int main(){
	int n;
	cin>>n;
	print(n);
}
