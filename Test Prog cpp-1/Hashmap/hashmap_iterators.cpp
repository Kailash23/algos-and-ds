#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
	unordered_map<string,int> ourmap;
	ourmap["abc"]=1;
	ourmap["def"]=2;
	ourmap["ghi"]=3;
	ourmap["ijk"]=4;
	ourmap["lmn"]=5;
	ourmap["opq"]=6;
	ourmap["qrs"]=7;
	ourmap["stv"]=8;
	ourmap["uvw"]=9;

	unordered_map<string,int>::iterator it = ourmap.begin();
	while(it != ourmap.end()) {
		cout<<"Key: "<<it->first<<" Value: "<< it->second<<endl;
		it++;
	}
	//find
	unordered_map<string,int>:: iterator it1 = ourmap.find("opq");
	//erase
	ourmap.erase(it1,ourmap.end());
	ourmap.erase("uvw");

	it = ourmap.begin();
	cout<<endl;
	while(it != ourmap.end()) {
		cout<<"Key: "<<it->first<<" Value: "<< it->second<<endl;
		it++;
	}
}
