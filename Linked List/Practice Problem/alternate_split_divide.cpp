/*
   Divide linked list in two

   Write a function that takes one list and divides up its nodes to create two smaller
   lists A and B. The sub lists should be made from alternating elements in the original list.
   Nodes should be in the reverse order of which they occurred in the source list.
   Print both linked lists in different lines.
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

void AlternatingSplit(node* head) {
	node *t1 = NULL, *t2 = NULL, *temp;
	while(head != NULL && head->next != NULL){

		temp = head->next;
		head->next = t1;
		t1 = head;
		head = temp;
		temp = temp->next;
		head->next = t2;
		t2 = head;
		head = temp;
	}
	if(head != NULL){
		head->next = t1;
		t1 = head;
	}
	printLL(t1);
	cout<<endl;
	printLL(t2);
	return;
}

int main(){
	node* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	AlternatingSplit(head);
}


/*
   1 2 3 4 5 6 -1
   1 2 3 4 5 6
   5 3 1
   6 4 2
 */
