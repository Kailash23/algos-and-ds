#include <iostream>
#include "ourmap.h"
using namespace std;

int main(){
	ourmap<int> map;
	for(int i = 0; i<10; i++) {
		char c = '0'+ i;
		string key = "abc";
		key = key + c;
		int value = i + 1;
		map.insert(key, value);
		cout << "Load Factor: " << map.getLoadFactor() << endl;
	}

	cout << "\n\nNo of entries in hashmap: " << map.size() << endl << endl;
	map.remove("abc2");
	map.remove("abc7");

	for(int i = 0; i <= 10; i++) {
		char c = '0'+ i;
		string key = "abc";
		key = key + c;
		cout << key << " : " << map.getValue(key) << endl;
	}
	cout << "\n\nNo of entries in hashmap: " << map.size() << endl;
}

/*
   Load Factor: 0.2
   Load Factor: 0.4
   Load Factor: 0.6
   Load Factor: 0.4
   Load Factor: 0.5
   Load Factor: 0.6
   Load Factor: 0.7
   Load Factor: 0.4
   Load Factor: 0.45
   Load Factor: 0.5


   No of entries in hashmap: 10

   abc0 : 1
   abc1 : 2
   abc2 : 0
   abc3 : 4
   abc4 : 5
   abc5 : 6
   abc6 : 7
   abc7 : 0
   abc8 : 9
   abc9 : 10
   abc: : 0


   No of entries in hashmap: 8
 */
