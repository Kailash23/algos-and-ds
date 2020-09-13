#include <iostream>
using namespace std;

#include <queue>

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.empty() << endl;

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

/*
   10
   20
   5
   0
   20
   30
   40
   50
   60
 */
