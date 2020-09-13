#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[arr[i]] = i + 1;
    }

    unordered_map<int, int>::iterator it;
    it = map.find(2);
    if (it != map.end()) {
        cout << "Element found";
    } else {
        cout << "Not found!";
    }
}
