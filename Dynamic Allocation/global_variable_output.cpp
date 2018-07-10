#include<iostream>
using namespace std;

int x = 1;

void print(){
    int x = 2;
    {
        int x = 3;
        cout << x << endl;      //3
    }
}
int main(){
    print();
    return 0;
}
