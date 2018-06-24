#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator it = v.begin();
	while(it != v.end()){
		cout<<*it<<endl;
		it++;
	}
	vector<int>::iterator it1 = v.begin();
	v.erase(it1);
	cout<<endl;

	it1= v.begin();
	while(it != v.end()){
		cout<<*it1<<endl;
		it1++;
	}

}
