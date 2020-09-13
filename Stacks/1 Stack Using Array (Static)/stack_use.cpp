#include <iostream>
using namespace std;

#include "stack_using_array.cpp"

int main() {
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}

/*
   Stack is Full !
   40
   40
   30
   2
   0
 */
