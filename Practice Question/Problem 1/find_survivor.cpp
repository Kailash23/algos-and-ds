/*
   100 people standing in a circle in an order 1 to 100. No. 1 has a sword. He kills the next person
   (i.e. No. 2) and gives the sword to the next (i.e. No. 3). All people do the same until only 1 survives.
   Who will survive at the last?
 */

#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

node* head = NULL;
node* tail = NULL;

void takeInput(int data){
	node* newNode = new node(data);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = tail->next;
	}
	tail->next = head;
}

void findSurvivor(){
	while(head->next != head){
		node* temp = head->next;
		head->next = head->next->next;
		head = head->next;
		delete(temp);
	}
	cout<<head->data;
}

int main(){
	for(int i = 1 ; i <= 100; i++){
		takeInput(i);
	}
	findSurvivor();
}

/*
   73
 */
