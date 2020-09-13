#include <iostream>
using namespace std;

#include "DynamicArray.cpp"

int main() {
    DynamicArray d1;
    d1.add(1);
    d1.add(2);
    d1.add(3);
    d1.add(4);
    d1.add(5);
    d1.add(6);
    d1.print();

    // Copy constructor will always do shallow copy.
    DynamicArray d2(d1);
    d1.add(0, 100);
    d2.print(); // Changes done in d1 will reflected to d2 only if inbuild copy constructor is used.

    // Copy assignment operator will always do shallow copy.
    DynamicArray d3;
    d3 = d1;
    d1.add(0, 10);
    d3.print();
}

/*
   1
   2
   3
   4
   5
   6

   1
   2
   3
   4
   5
   6

   100
   2
   3
   4
   5
   6
 */
