/*
   Swap two Node of LL

   Given a linked list, i & j, swap the nodes that are present at i & j position in the LL. You need to swap the entire nodes, not just the data.
   Indexing starts from 0. You don't need to print the elements, just swap and return the head of updated LL.
   Assume i & j given will be within limits. And i can be greater than j also.

   Input format :
   Line 1 : Linked list elements (separated by space and terminated by -1)
   Line 2 : i and j (separated by space)
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

node* swap_nodes(node* head, int i, int j){

}

int main(){
	node* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	int i = 0;
	int j = 6;
	head = swap_nodes(head, i, j);
	printLL(head);
}


/*

 */
