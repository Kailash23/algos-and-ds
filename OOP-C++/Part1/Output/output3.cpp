#include<iostream>
using namespace std;

class Pair {
public :
    int first;
    int second;
};

int main() {
    Pair p1;
    p1.first = 10;
    p1.second = 20;
    Pair p2;
    p2 = p1;
    cout << p2.first << " " << p2.second << endl;
}

/*
   10 20
 */
