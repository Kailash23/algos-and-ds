#include <iostream>
using namespace std;

int main(){
	int arr[] = {4, 5, 6, 7};
	int *p = (arr + 1);
	cout << *arr + 9 <<endl;        //13
	cout<<p<<endl;      //0x61ff10
	cout<<*p<<endl;     //5
	cout<<arr+1<<endl;      //0x61ff10
	cout<<arr+2<<endl;      //0x61ff14
	cout<<p+2<<endl;        //0x61ff18
	return 0;
}
