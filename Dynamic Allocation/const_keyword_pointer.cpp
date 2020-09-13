#include <iostream>
using namespace std;

int main() {
    int const i = 10;
    //int *p = &i;	error: can't store address of constant variable
    int const *p = &i; //p is pointer to constant integer
    //(*p)++;		error: read-only variable is not assignable

    int s = 12;
    int const *p2 = &s;
    cout << *p2 << endl; //12
    s++;
    cout << *p2 << endl; //13

    //(*p2)++;		error: increment of read only.
}
