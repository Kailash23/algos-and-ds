#include <iostream>
using namespace std;
#include "Node.cpp"

/*
   Function to input data into linked list.
   Time Complexity : O(n)
 */

Node* takeInputBetter(){
	int data;
	cin >> data;
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
		cin >> data;
	}
	return head;
}

/*
	// Runtime error in 2 inputs

   Node* deleteNode(Node* head, int i){
        Node* temp = head;
        if(i == 0){
                Node* a = head;
                head = head->next;
                delete(a);
                return head;
        }

        int count = 0;
        while(temp != NULL && count < i-1){
                count++;
                temp = temp->next;
        }

        if(head != NULL){
                Node* d = temp->next;
                temp->next = temp->next->next;
                delete(d);
                return head;
        }
   }

   Node* deleteNode(Node* head, int i){
        Node* temp1 = head;
        if(i == 0){
                head = temp1->next;
                delete(temp1);
                return head;
        }
        for(int j = 0; j < i-1 ; j++){
                temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
        return head;
   }
*/

Node* deleteNode(Node* head, int i){
	Node* temp = head;
	while(i > 1) {
		if(temp == NULL) {
			return head;
		}
		temp = temp->next;
		i--;
	}
	if(temp->next != NULL && temp->next->next != NULL) {
		temp->next = temp->next->next;
	}
	return head;
}

/*
	Node* deleteNode(Node* head, int i){
		if(head == NULL){
			return head;
		}
		if(i == 0){
			Node* temp = head->next;
			delete head;
			return temp;
		}
		Node* temp = head;
		int count = 0;
		while(temp != NULL && count < i - 1){
			temp = temp->next;
			count++;
		}
		if(temp == NULL){
			return head;
		}
		if(temp->next != NULL){
			temp->next = temp->next->next;
		}
		return head;
	}
*/

void printLL(Node* head){
	while (head!=NULL) {            //This will traverse to the last node
		cout << head->data << " ";
		head = head->next;
	}
}

int main(){
	Node *head = takeInputBetter();
	printLL(head);
	cout << endl;
	int pos;
	cin >> pos;
	head = deleteNode(head, pos);    // Returning updated value of head in main
	printLL(head);
}

/*
   Linked list elements (separated by space and terminated by -1)
 */

/*
   1 2 3 4 5 6 7 -1
   1 2 3 4 5 6 7
   5
   1 2 3 4 5 7
 */
