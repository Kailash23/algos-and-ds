#include <iostream>
using namespace std;

#include "Node.cpp"

/*
   Function to input data into linked list.
   Time Complexity : O(n)
   We are maintaining pointer (ie tail) to the last node of linked list along with head
   (which point to first node). So that we can avoid while loop inside else statement
   which travesing to find second last element in the linked list and then linking it.
   This will bring down our time complexity to O(1)
 */

Node *takeInputBetter() {
    int data;
    cin >> data;
    Node *head = NULL; // Head for pointing first node of linked list
    Node *tail = NULL; // Tail for pointing last node of linked list
    while (data != -1) {
        Node *newNode = new Node(data); // Dynamically allocating newNode
        if (head == NULL) {             // If linked list is empty initially
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode; // Pointing tail node (currently last node) to the newly created node.
            tail = tail->next;    // Point newly added node as tail.
                                  // OR
                                  // tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node *revHead = NULL;

void reverseLL(Node *p) {
    if (p->next == NULL) {
        revHead = p;
        return;
    }
    reverseLL(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

/*
   Function to print linked list.
 */

void printLL(Node *head) {
    while (head != NULL) { //This will traverse to the last node
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node *head = takeInputBetter();
    cout << "Original:" << endl;
    printLL(head);
    reverseLL(head);
    cout << "\nReverse:" << endl;
    printLL(revHead);
}

/*
   Linked list elements (separated by space and terminated by -1)
 */

/*
   4 3 1 2 6 7 9 -1
   Original:
   4 3 1 2 6 7 9
   Reverse:
   9 7 6 2 1 3 4
 */
