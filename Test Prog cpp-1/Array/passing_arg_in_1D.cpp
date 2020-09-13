#include <iostream>
using namespace std;
void ShowArray(int *a) {
    for (int col = 0; col < 3; ++col) {
        cout << a[col] << " ";
    }
}

int main() {
    int map[] = {1, 2, 3};
    ShowArray(map);
}
