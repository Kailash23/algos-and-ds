#include<iostream>
using namespace std;

int main(){
	const int i = 10;
	int const s = 5;		//alternate way

	int j = 12;
	//constant reference from non const int
	const int & k = j;		//path constant not actual storage
	j++;
	//k++;		error: increment of read-only reference 'k'
	cout<<k<<endl;

	//constant reference from const int
	int const j2 = 12;
	int const &k2 = j2;

	//reference from a const int
	int const j3 = 123;		//read access only
	//int & k3 = j3;		//k3 -> reference of j3( we cant't make k3 )
	//k3++;		error: binding 'const int' to reference of type 'int&' discards qualifiers

	//If you have read only path u cant make both read-write path from that
}
