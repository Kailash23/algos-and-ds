#include "Node.h" // Node class code will be placed here replacing this line and " " search in current folder.
#include <climits>

template <typename T> // have to mention for every class

class Stack {
    Node<T> *head;
    int count; // Maintain num of element in stack

  public:
    Stack() {
        head = NULL;
        count = 0;
    }

    /*
	   Return the number of elements present in stack - O(1)
	 */
    int size() {
        return count;
    }

    /*
	   Stack is empty or not	- O(1)
	 */
    bool isEmpty() {
        return size() == 0;
    }

    /*
       Insert element into stack - O(1)
	 */
    void push(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    /*
	   Delete top element - O(1)
	 */
    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        T data = head->data;
        head = head->next;
        count--;
        return data;
    }

    /*
	   Return top element - O(1)
	 */
    T top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return head->data;
    }
};

/*
   Using Linked List (Insertion Beginning)

   push - O(1)
   pop - O(1)
   top - O(1)
   size - O(1)
   isEmpty - O(1)
 */
