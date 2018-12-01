#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char s1[] = {"west"};
	char s2[] = {"world"};
	strcpy(s1, s2);
	cout << s1;       //world
}
//strcpy(dest, source);
