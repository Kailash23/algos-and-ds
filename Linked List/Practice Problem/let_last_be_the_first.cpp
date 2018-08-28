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

class node {
	public:
	int data;
	node *next;
	node(int data){
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

node* takeInput_Better(){
	int data;
	cin>>data;
	node *head = NULL;              // Head will point to first node
	node *tail = NULL;              // Tail will point to last node
	while(data != -1) {
		node *newNode = new node(data);         // Dynamically allocating newNode
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

void printLL(node* head){
	while (head != NULL) {            // This will traverse to the last node
		cout<<head->data<<" ";
		head = head->next;
	}
}

node* moveToFront(node* head){
	node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	node* a = temp->next;
	temp->next = NULL;
	a->next = head;
	head = a;
	return head;
}

int main(){
	node* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	head = moveToFront(head);
	printLL(head);
}

/*
   1 2 3 4 5 6 7 -1
   1 2 3 4 5 6 7
   7 1 2 3 4 5 6
 */
