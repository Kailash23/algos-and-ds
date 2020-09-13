#include <iostream>
#include <unordered_map>
using namespace std;

bool findPairs(int arr[], int n) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (map.count(sum) > 0) {
                return true;
            }
            map[sum]++;
        }
    }
    return false;
}

int main() {
    int arr[] = {9, 8, 17, 10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = findPairs(arr, n);
    cout << ans << endl;
}
