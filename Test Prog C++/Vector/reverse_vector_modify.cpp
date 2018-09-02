//Reverse a vector

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVec(vector<int> v){
	for(int i = 0; i < v.size(); i++) {
		cout<< v[i] <<" ";
	}
}

int main(){
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	vector<int>* p = &vec;
	reverse(p->begin(), p->end());		// arrow operator used
	printVec(vec);
}
