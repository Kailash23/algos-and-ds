/*
   copying one vector to by assignment operator.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1(5, 7);
    vector<int> vec2;
    vec2 = vec1;
    vec2.push_back(5);
    vector<int>::iterator it = vec2.begin();
    while (it != vec2.end()) {
        cout << *it << endl;
        it++;
    }
}
