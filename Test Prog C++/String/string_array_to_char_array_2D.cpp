#include <iostream>
using namespace std;

int main()
{
	char foo[3][3] = {{'a','b','c'}, {'d','e','f'},{'g','h','i'}};
	string bar[3];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			bar[i] += foo[i][j];
		}
	}
	for(int i = 0; i < 3; i++) {
		cout << bar[i] << endl;
	}
	return 0;
}
