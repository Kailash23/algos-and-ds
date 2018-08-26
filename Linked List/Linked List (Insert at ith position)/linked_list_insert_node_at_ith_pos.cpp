#include <iostream>
using namespace std;
#include "Node.cpp"

/*
   Function to input data into linked list.
   Time Complexity : O(n)
 */

Node* takeInput_Better(){
	int data;
	cin>>data;
	Node *head = NULL;              // Head will point to first node
	Node *tail = NULL;              // Tail will point to last node
	while(data != -1) {
		Node *newNode = new Node(data);         // Dynamically allocating newNode
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

Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);		// Creating Node to be inserted
	int count = 0;
	Node *temp = head;

	if(i == 0) {		// Special case for inserting at 0th location
		newNode -> next = head;		// Making new node as first node
		head = newNode;		// Changing head Node
		return head;		// Returning head in order to make changes to the main's head
	}

	while(temp != NULL && count < i - 1) {		// This will move temp to (i-1)th node.
		temp = temp -> next;
		count++;
	}

	if(temp != NULL) {		// temp != NULL is imp to avoid segmentation fault. (NULL->next)
		// Node *a = temp -> next;		// a act as temp pointer variable
		// temp -> next = newNode;
		// newNode -> next = a;
		// OR
		newNode->next = temp->next;		// Storing ith node address into newNode's next
		temp->next = newNode;		// (i-1)th node point to newNode
	}
	return head; 
}

/*
   Function to print linked list.
 */

void printLL(Node* head){
	while (head!=NULL) {            //This will traverse to the last node
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main(){
	//Node *head = takeInput();
	Node *head = takeInput_Better();
	printLL(head);
	cout<<"\n";
	int data, pos;
	cin>>data>>pos;
	head = insertNode(head,pos,data);	// Returning updated value of head in main
	printLL(head);
}

/*
   Linked list elements (separated by space and terminated by -1)
 */

/*
   1 2 3 4 5 6 7 -1
   1 2 3 4 5 6 7
   99 3
   1 2 3 99 4 5 6 7
 */
