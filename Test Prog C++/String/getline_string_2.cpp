#include <iostream>
int main()
{
	using namespace std;

	char name[20];       //declaring string 'name'

	cin.getline(name, sizeof(name)); //taking string input
	cout << name << endl; //printing string
	return 0;
}
