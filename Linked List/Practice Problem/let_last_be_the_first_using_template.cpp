/*
   Let last be the first

   Write a function that moves last element to front in a given singly Linked List.
   For example, if the given Linked List is 1->2->3->4->5, then the function should
   change the list to 5->1->2->3->4.
   You just need to return the head of new linked list, don't print the elements.
   Input format :
   Line 1 : Linked list elements of length n (separated by space and terminated by -1)
 */

#include <iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node *next;
	Node(T data){
		this->data = data;
		next = NULL;
	}
	~Node(){
		if(next != NULL){
			delete next;
		}
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

Node<int>* takeInput_Better(){
	int data;
	cin>>data;
	Node<int> *head = NULL;              // Head will point to first node
	Node<int> *tail = NULL;              // Tail will point to last node
	while(data != -1) {
		Node<int> *newNode = new Node<int>(data);         // Dynamically allocating newNode
		if(head == NULL) {               // If linked list is empty initially
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;           // Pointing tail node (currently last node) to the newly formed node.
			tail = tail->next;
			// OR
			// tail = newNode;
		}
		cin>>data;
	}
	return head;
}

/*
   Function to print linked list.
 */

void printLL(Node<int>* head){
	while (head != NULL) {            // This will traverse to the last node
		cout<<head->data<<" ";
		head = head->next;
	}
}

Node<int>* moveToFront(Node<int>* head){
	Node<int>* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	Node<int>* a = temp->next;
	temp->next = NULL;
	a->next = head;
	head = a;
	return head;
}

int main(){
	Node<int>* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	head = moveToFront(head);
	printLL(head);
}

/*
   1 2 3 4 5 6 7 8 9 -1
   1 2 3 4 5 6 7 8 9
   9 1 2 3 4 5 6 7 8
 */


/* Alternative Solution

   Node<int>* moveToFront(Node<int>* head_ref) {
        if (head_ref == NULL || (head_ref)->next == NULL)
                return head_ref;
        Node<int>* secLast = NULL;
        Node<int>* last = head_ref;
        while (last->next != NULL) {
                secLast = last;
                last = last->next;
        }
        secLast->next = NULL;
        last->next = head_ref;
        head_ref = last;
        return head_ref;
   }
 */
