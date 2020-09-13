#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;
    // Insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // Find or Access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;
    cout << ourmap.at("ac") << endl; // Error
    cout << ourmap["gh"] << endl;    // It will insert 0 if 'gh' is not present as a key

    // Check Presence
    if (ourmap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    } else {
        cout << "not present" << endl;
    }

    // Size
    cout << ourmap.size();

    // Erase
    ourmap.erase("gh");
}

/*
   1
   1
   terminate called after throwing an instance of 'std::out_of_range'
   what():  _Map_base::at
 */
