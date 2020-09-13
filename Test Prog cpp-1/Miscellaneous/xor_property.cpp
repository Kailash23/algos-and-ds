#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 1, 2, 2, 4, 5, 4, 5};
    int s = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    for (int i = 0; i < s; i++) {
        k = k ^ arr[i];
    }
    cout << k;
}
