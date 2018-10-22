#include<climits>
#include"Node.h"

template <typename T>		// have to mention for every class

class Stack {
	Node<T>* head;
	Node<T>* tail;
	int count;		// Maintain num of element in stack

public:
	Stack(){
		head = NULL;
		tail = NULL;
		count = 0;
	}

	/*
	   Return the number of elements present in stack - O(1)
	 */
	int size(){
		return count;
	}

	/*
	   Stack is empty or not - O(1)
	 */
	bool isEmpty(){
		return size() == 0;
	}

	/*
       Insert element into stack - O(1)
	 */
	void push(T data){
		Node<T>* newNode = new Node<T>(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;	// Insertion at end
			tail = tail->next;
		}
		count++;
	}

	/*
	   Delete top element - O(n)
	 */
	T pop(){
		if(isEmpty()){
			cout << "Stack is empty" << endl;
			return INT_MIN;
		}
		Node<T>* temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		int data = temp->next->data;
		free(temp->next);
		temp->next = NULL;
		tail = temp;
		count--;
		return data;
	}

	/*
	   Return top element - O(1)
	 */
	T top(){
		if(isEmpty()){
			cout << "Stack is empty" << endl;
			return INT_MIN;
		}
		return tail->data;
	}
};

/*
   Using Linked (Insertion End)

   push - O(1)
   pop - O(n)
   top - O(1)
   size - O(1)
   isEmpty - O(1)
 */
