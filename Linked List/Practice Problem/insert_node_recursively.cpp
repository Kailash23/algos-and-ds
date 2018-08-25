#include <iostream>
using namespace std;

class Node {
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
	while (head!=NULL) {            // This will traverse to the last node
		cout<<head->data<<" ";
		head = head->next;
	}
}

Node* insertNodeRec(Node* head, int i, int data){

	if(head == NULL){		// If head is null initially
		if(i == 0){			// If inserting at 0th location
			Node* newNode = new Node(data);		// Make new node and return it which will act as head.
			return newNode;
		} else {
			return head;	//If not inserting at 0th location then return head.
		}
	}

	Node* newNode = new Node(data);
	if(i == 0){				// If head is not null initially & inserting at 0th location
		newNode->next = head;		// connect newNode to head
		head = newNode;				// Make newNode as head of LL and return it
		return head;
	}
	head->next = insertNodeRec(head->next, i-1, data);		//TODO:Ask Doubt
	return head;
}

int main(){
	Node* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	int i = 4;
	int data = 10;
	head = insertNodeRec(head, i, data);
	printLL(head);
}
