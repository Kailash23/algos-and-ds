/*
   Print ith node

   Given a linked list and a position i, print the node at ith position.
   If position i is greater than length of LL, then don't print anything.
   Indexing starts from 0.
   Input format :
   Line 1 : Linked list elements (separated by space and terminated by -1)
   Line 2 : Integer i (position)
 */

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

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

/*
   Function that will print the ith node's data in a linked list
 */
 void printIthNode(Node *head, int i) {
     Node* temp = head;
	 int k = 0;
	 while(temp != NULL){
		 if(k == i){
			 cout<< temp->data <<endl;
		 }
		 k++;
		 temp = temp->next;
	 }
 }


int main(){
	Node* head = takeInput_Better();
	int ith = 4;
	printIthNode(head, ith);
}
