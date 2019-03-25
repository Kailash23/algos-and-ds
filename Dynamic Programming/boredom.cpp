/* Incomplete Solution*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int solve(int n, vector<int> A) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[A[i]]++;
    }

    // unordered_map<int,int>:: iterator it = map.begin();
    // while (it != map.end()) {
    // 	cout<< "Key: " << it->first<<" Value: "<< it->second<<endl;
    // 	it++;
    // }
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    solve(n, v);
}
