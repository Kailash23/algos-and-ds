#include <iostream>
using namespace std;

void f(int *p) {
    (*p)++;
}

void g(const int *p) {
    //(*p)++;		//This fucntion can't change value , will give error.
    //p is not assignable it a read only copy.
}

void h(int &a) { //Changes will reflect
    a++;         //Because passed by reference.
}

void z(int const &b) {
    //b++;		//error: increment of read-only reference 'b'
}

int main() {
    //1
    int i = 0;
    f(&i);
    cout << i << endl; //1

    int s = 4;
    g(&s);
    cout << s << endl;

    int k = 6;
    h(k); //passed by reference
    cout << k << endl;

    int l = 9;
    z(l);
    cout << k << endl;

    //2
    int m = 12;
    int n = 2;
    int const *p1 = &m; //p1 is pointer to constant integer
    p1 = &n;            //We can do this but we can't do *(p)++.
    //(*p1)++;		//This will give error
    cout << *p1; //Should give 2 as output

    int *const p2 = &m; //p2 is constant pointer to integer (readeability: right to left)
    //p2 = &n;		//This will give error
    (*p2)++; //This will work fine

    int const *const p3 = &m; //p3 is constant pointer to a constant integer.
                              // (*p3)++;		//Can't do will get error.
                              // p3 = &n;		//Can't do will get error.
}
