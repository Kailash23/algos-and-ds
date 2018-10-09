/*
   Palindrome LinkedList

   Check if a given linked list is palindrome or not. Return true or false.
   Indexing starts from 0.

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

node* takeInputBetter(){
	int data;
	cin >> data;
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
		cin >> data;
	}
	return head;
}

/*
   Function to print linked list.
 */

void printLL(node* head){
	while (head != NULL) {            // This will traverse to the last node
		cout << head->data << " ";
		head = head->next;
	}
}

node* reverseLL(node *head){
	if(head == NULL || head->next == NULL) {
		return head;		// will return head - if there is no node and only one node.
	}
	node* smallHead = reverseLL(head->next);		// Will stack func call till we get last node (smallHead will always contain last node address)
	head->next->next = head;	// All stacked call will execute here (these lines will execute for the first time for 2nd last node of LL)
	head->next = NULL;			// And will reverse all the links from last node to the mid of LL
	return smallHead;		// return the last node address (which is head for reversed half part.)
}

bool checkPallindrome(node* head) {
	node *i, *temp;
	i = head;
	temp = head;            // Both i and temp points to head of linked list.
	while(temp != NULL && temp->next != NULL) {             //This loop's purpose is to move i to MID of linked list and temp to END of the Linked List.
		i = i->next;            // Moving i by one step (i will point to mid of linked list after loop ends)
		temp = temp->next->next;                // Moving temp by 2 steps. Loop will end when temp is Null or temp->next is NULL
	}
	node* smallHead = reverseLL(i);               // smallHead will be the head of reversed linked list (ie last node of the whole linked list)
	temp = head;            // temp is pointed to the head (beginning)
	/*
	   We basically reversed the link of the second part of the linked list.  This will make linked list like this.
	   [temp(1)]->[(2)]->[(3)]->[(4)(NULL)]<-[(3)]<-[(2)]<-[(1)smallHead]
	 */
	while(temp != NULL && smallHead != NULL) {		// Moving from start and end of linked list to mid of linked list till we got NULL.
		if(temp->data == smallHead->data) {
			temp = temp->next;		// Increment both temp and smallHead
			smallHead = smallHead->next;
		} else {
			return false;
		}
	}
	return true;
}

int main(){
	node* head = takeInputBetter();
	printLL(head);
	cout << endl;
	bool ans = checkPallindrome(head);
	if(ans) {
		cout << "Palindrome!";
	} else {
		cout << "Not Palindrome!";
	}
}

/*
   Sol:

   We can't move backward in single linked list.
   1st way : Check data at head of linked list with the last node data if its same then
             check data at node after head with the second last node's data. And keep
             repeating the process.

				Time Complexity : O(n^2)

   2nd way : Make a new copy of linked list in a reverse order of the original one. Then
             check each element one by one in both the linked list.

				Time Complexity : O(n) Space Complexity : O(n)

   3rd way : Break the linked list in 2 half and reverse the second part.
             To check palindrome, we just have to reverse latter half of linked list and
             then we can in (n/2) steps total can compare if all elements are same or not.
             For finding mid point, first we can in O(N) traverse whole list and calculate
             total number of elements. Reversing is again O(N).

				  Midpoint - O(n)
                  Reversing - O(n/2) ~ O(n)
                  Time Complexity : O(n) Sapce Complexity O(1)
 */

/*
   1 2 3 4 3 2 1 -1
   1 2 3 4 3 2 1
   Palindrome!
 */
