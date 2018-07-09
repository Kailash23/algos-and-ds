#include<iostream>
using namespace std;

int main(){
	int *p = new int;		//Dyanamic allocation (int variable)
	*p = 10;
	cout<<*p<<endl;

	int* arr = new int[50];		//Dyanamic allocaation of 1D aaarray
	// 200 bytes on heap(for array) and 4 or 8 bytes on stack (for pointer).
	// Dynamic memory allocated doesn't deallocate when scope is over.
	int n;
	cout<<"Enter elements: ";
	cin>>n;
	int* ar = new int[n];		//At Runtime
	ar[0] = 10;
	*(ar+1) = 5;

	cout<<ar[0]<<endl;
	cout<<ar[1]<<endl;

	cout<<p<<endl;		//0x8d6c98

	delete p;		//Single element deletion
	delete [] arr;		//Array deletion
	delete [] ar;		//This doesn't clear the pointer it clear memory pointed by pointer.

	int *s;
	s = new int;
	delete s;

	cout<<p<<endl;		//0x746c98
}
