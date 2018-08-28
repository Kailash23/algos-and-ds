/*
   Skip M nodes and Delete n nodes

   Given a linked list and two integers M and N. Traverse the linked list such that you
   retain M nodes then delete next N nodes, continue the same until end of the linked list.
   That is, in the given linked list you need to delete N nodes after every M nodes.
   Input format :

   Line 1 : Linked list elements (separated by space and terminated by -1)
   Line 2 : M
   Line 3 : N

   Sample Input 1 :
   1 2 3 4 5 6 7 8 -1
   2
   2

   Sample Output 1 :
   1 2 5 6
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

node* skipMdeleteN(node *head, int M, int N) {
	if(M == 0){			// If M is 0 there will be only deletion. Whole LL is deleted
		return NULL;
	}
	node* curr = head, *t;
	int count;

	while(curr){
		for(count = 1; count < M && curr != NULL; count++){		// basically skipping first M nodes if its not NULL and count < M. (Will run M-1 times)
			curr = curr->next;
		}

		if(curr == NULL){		// If we reached the node after last node while skipping return head of LL. As nothing to delete anymore.
			return head;
		}

		t = curr->next;		// t points to node after current node. which is used for deleting next N nodes.

		for(count = 1; count <= N && t != NULL; count++){		// Will run N times
			node* temp = t;		// Making temp to point to t
			t = t->next;		// Incrementing t to next node.
			delete(temp);		// deleting temp
		}
		curr->next = t;		// linking curr and t as N nodes deleted between them
		curr = t;		// Moving curr to t
	}
	return head;
}

int main(){
	node* head = takeInput_Better();
	printLL(head);
	cout<<endl;
	int m, n;
	cin>>m>>n;
	head = skipMdeleteN(head, m, n);
	printLL(head);
}

/*
   1 2 3 4 5 6 7 8 9 10 -1
   1 2 3 4 5 6 7 8 9 10
   2 3
   1 2 6 7
 */
