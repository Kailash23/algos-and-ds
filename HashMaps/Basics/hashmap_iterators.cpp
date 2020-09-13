#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["def"] = 2;
    ourmap["ghi"] = 3;
    ourmap["ijk"] = 4;
    ourmap["lmn"] = 5;
    ourmap["opq"] = 6;
    ourmap["qrs"] = 7;
    ourmap["stv"] = 8;
    ourmap["uvw"] = 9;

    unordered_map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end()) {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        it++;
    }
    // Find
    unordered_map<string, int>::iterator it1 = ourmap.find("opq");
    // Erase
    ourmap.erase(it1, ourmap.end());
    ourmap.erase("uvw");

    it = ourmap.begin();
    cout << endl;
    while (it != ourmap.end()) {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        it++;
    }
}

/*
   Key: uvw Value: 9
   Key: qrs Value: 7
   Key: stv Value: 8
   Key: lmn Value: 5
   Key: def Value: 2
   Key: ghi Value: 3
   Key: opq Value: 6
   Key: abc Value: 1
   Key: ijk Value: 4

   Key: qrs Value: 7
   Key: stv Value: 8
   Key: lmn Value: 5
   Key: def Value: 2
   Key: ghi Value: 3
 */
