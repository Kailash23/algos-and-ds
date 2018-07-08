#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v1{1,2,3,4,5,6};
	vector<int>::iterator it1, it2;
	it1 = v1.begin();
	it2 = v1.end();
	it2--;
	v1.erase(it1,it2);

	for(auto it = v1.begin(); it!=v1.end();it++){
		cout<<" "<<*it;
	}
	return 0;
}
