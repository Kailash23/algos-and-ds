/*
   Length of LL (recursive)

   Given a linked list, find and return the length of input LL recursively.
   Input format :
   Linked list elements (separated by space and terminated by -1)
 */
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
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

void printLL(Node* head){
	while (head!=NULL) {            //This will traverse to the last node
		cout<<head->data<<" ";
		head = head->next;
	}
}

int length(Node *head) {
	if(head == NULL){
		return 0;
	}
	return 1 + length(head->next);
}

int main(){
	Node* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	cout<< length(head) <<endl;

}
