#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> *vec = new vector<int>();
    vec->push_back(10);
    vec->push_back(20);
    vec->push_back(30);
    vec->push_back(40);
    vec->push_back(50);

    int n = vec->size();

    for (int i = 0; i < n; i++) {
        cout << vec->at(i) << " ";
    }
}
