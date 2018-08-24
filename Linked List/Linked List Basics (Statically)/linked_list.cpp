#include <iostream>
using namespace std;
#include "Node.cpp"

printLL(Node* head){
	Node *temp = head;		// We don't want to loose track of head so using temp pointer
	while(temp != NULL) {            // Dont use head->next != NULL (It will not print last value)
		cout<< temp->data <<" ";
		temp = temp->next;
	}
}

// If you want to stop at node before last node use head->next != NULL

int main(){
	// Statically allocated node
	Node n1(1);
	Node *head = &n1;               // Head

	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);

	// Connecting nodes
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	/*
	   // Printing data
	   cout<< n1.data <<" " << n2.data <<endl;

	   // Using head
	   cout<< head->data <<endl;
	 */
	printLL(head);
}

/*
   1 2 3 4 5
 */
