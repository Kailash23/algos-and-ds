#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    node2->next = node1;
    print(node2);
}

/*
   20 10
 */
