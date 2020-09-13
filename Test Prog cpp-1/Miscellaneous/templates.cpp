#include <iostream>
using namespace std;

//Generic datatype
template <class T>
T addcrap(T a, T b) {
    return a + b;
}

int main() {
    string x = "a", y = "b", z;
    z = addcrap(x, y);
    int k = 0, s = 3, t;
    t = addcrap(k, s);
    cout << z << endl;
    cout << t << endl;
}
