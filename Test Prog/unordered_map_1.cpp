#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
	unordered_map<string,int> ourmap;
	//insert
	pair<string,int> p ("abc",1);
	ourmap.insert(p);
	ourmap["def"] = 2;

	//find or access
	cout<<ourmap["abc"]<<endl;
	cout<<ourmap.at("abc")<<endl;
	//cout<<ourmap.at("ac")<<endl; //error
	cout<<ourmap["gh"]<<endl; // It will insert 0

	//check presence
	if(ourmap.count("ghi")>0){  //0,1
		cout<<"ghi is present"<<endl;
	} else {
		cout<<"not present"<<endl;
	}

	//size
	cout<<ourmap.size();

	//erase
	ourmap.erase("gh");

}
