#include <iostream>
using namespace std;
#include "Node.cpp"

int main() {
    // Dynamically allocated node
    Node *n1 = new Node(10);
    Node *head = n1;

    Node *n2 = new Node(20);

    // Connecting node
    n1->next = n2;
}
