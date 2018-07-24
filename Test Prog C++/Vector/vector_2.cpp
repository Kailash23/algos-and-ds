#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v(4,12);
	v.push_back(15);
	cout << v.size() <<""<< v.capacity();
}
