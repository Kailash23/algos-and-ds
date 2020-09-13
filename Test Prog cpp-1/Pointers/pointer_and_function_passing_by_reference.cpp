#include <iostream>
using namespace std;

void Change(int *a) {
    *a = 3;
}

int main() {
    int a = 2;
    Change(&a);
    cout << a;
}
