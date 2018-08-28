/*
   Even after Odd LinkedList

   Arrange elements in a given Linked List such that, all even numbers are placed
   after odd numbers. Respective order of elements should remain same.
   You don't need to print the elements, instead return the head of updated LL.
   Input format : Linked list elements (separated by space and terminated by -1)`
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

node* arrange_LinkedList(node* head){
	node *oddH = NULL;		// odd LL head
	node *oddT = NULL;		// odd LL tail
	node *evenH = NULL;		// even LL head
	node *evenT = NULL;		// even LL tail

	node* temp = head;		// temp points head

	while(temp != NULL){
		int val = temp->data;
		if(val % 2 == 0){		// if data is even
			if(evenH == NULL){			// if there is no even node yet
				evenH = temp;
				evenT = temp;
			} else {				//append to tail of even LL and inc even LL's tail
				evenT->next = temp;
				evenT = evenT->next;
			}
		} else {		// if data is odd
			if(oddH == NULL){		// if there is no odd node yet
				oddH = temp;
				oddT = temp;
			} else {				// append to tail of odd LL and inc odd LL's tail
				oddT->next = temp;
				oddT = oddT->next;
			}
		}
		temp = temp->next;		// keep moving temp forward for checking (odd / even)
	}

	if(oddH == NULL || evenH == NULL){		// If either odd list or even list is empty,no change is required as all elements are either even or odd.
		return head;
	}

	oddT->next = evenH;
	evenT->next = NULL;
	head = oddH;		// Modify head pointer to starting of odd list.
	return head;		// and return it.
}

int main(){
	node* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	head = arrange_LinkedList(head);
	printLL(head);
}


/*
   1 2 3 4 5 0 6 7 8 9 -1
   1 2 3 4 5 0 6 7 8 9
   1 3 5 7 9 2 4 0 6 8
 */
