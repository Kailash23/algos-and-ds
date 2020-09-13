#include <iostream>
using namespace std;

void Func(int arr[]) {
    cout << "\nFunction: " << sizeof(arr);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Main: " << sizeof(arr);
    Func(arr);
}
