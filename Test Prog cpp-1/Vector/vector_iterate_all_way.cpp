#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec; // Declaration

    vec.push_back(2); // Insertion
    vec.push_back(3);
    vec.push_back(4);

    for (int i = 0; i < vec.size(); i++) { // Iterate
        cout << vec[i] << " ";
    }

    cout << endl;

    for (int x : vec) {
        cout << x << " ";
    }

    cout << endl;

    for (auto i : vec) {
        cout << i << " ";
    }

    cout << endl;

    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
}

/*
   2 3 4
   2 3 4
   2 3 4
   2 3 4
 */
