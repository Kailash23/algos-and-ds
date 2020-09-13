/*
   kReverse

   Implement kReverse( int k ) in a linked list i.e. you need to reverse first K
   elements then reverse next k elements and join the linked list and so on.
   Indexing starts from 0. If less than k elements left in the last, you need to
   reverse them as well. If k is greater than length of LL, reverse the complete LL.
   You don't need to print the elements, just return the head of updated LL.
 */

#include <iostream>
using namespace std;

class node {
  public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

/*
   Function to input data into linked list.
   Time Complexity : O(n)
   We are maintaining pointer (ie tail) to the last node of linked list along with head
   (which point to first node). So that we can avoid while loop inside else statement
   which travesing to find second last element in the linked list and then linking it.
   This will bring down our time complexity to O(1).
 */

node *takeInput_Better() {
    int data;
    cin >> data;
    node *head = NULL; // Head will point to first node
    node *tail = NULL; // Tail will point to last node
    while (data != -1) {
        node *newNode = new node(data); // Dynamically allocating newNode
        if (head == NULL) {             // If linked list is empty initially
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode; // Pointing tail node (currently last node) to the newly formed node.
            tail = tail->next;
            // OR
            // tail = newNode;
        }
        cin >> data;
    }
    return head;
}

/*
   Function to print linked list.
 */

void printLL(node *head) {
    while (head != NULL) { // This will traverse to the last node
        cout << head->data << " ";
        head = head->next;
    }
}

node *reverse_linked_list(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *smallHead = reverse_linked_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

node *kReverse(node *head, int n) {
    if (n == 1) { // If k is 1 return head of linked as nothing to be reversed.
        return head;
    }
    int i = 1;
    node *temp = head, *head1 = head, *head2 = head;
    while (temp != NULL) {
        if (i % n == 0 || temp->next == NULL) { // Will enter loop only if i = k ,2k , 3k.. OR we reached the last node
            /*
				temp will point to kth , 2*kth and so on.
			*/
            node *head3 = temp->next; // head3 point to node after kth node
            temp->next = NULL;        // Make temp's next field NULL (So that recursion will have terminating condition for first k nodes). Also replaced field value is stored in head3
            node *h = head2;
            head2 = reverse_linked_list(head2); //head2 will point to last node and served as head of reversed part of linked list.
            if (head1 == head) {
                head1 = head2;
                head = head2;
            } else {
                head1->next = head2;
            }
            h->next = head3; // connecting last node of reversed linked list to first node of other part.
            head1 = h;
            head2 = head3;
            temp = head3;
        } else { // If i != k , 2k ,3k then increment temp
            temp = temp->next;
        }
        i++;
    }
    return head;
}

int main() {
    node *head = takeInput_Better();
    printLL(head);
    cout << endl;
    int k = 3;
    head = kReverse(head, k);
    printLL(head);
}

/*
   1 2 3 4 5 6 7 8 9 -1
   1 2 3 4 5 6 7 8 9
   3 2 1 6 5 4 9 8 7
 */
