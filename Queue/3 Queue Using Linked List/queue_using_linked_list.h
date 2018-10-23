template <typename T>

class Node {
public:
	T data;
	Node<T>* next;

	Node(T data){
		this->data = data;
		next = NULL;
	}
};

template<typename T>

class QueueUsingLL {
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	QueueUsingLL(int s){
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size == 0;
	}

	/*
	   Insertion from rear
	 */
	void enqueue(T element){
		Node<T>* newNode = new Node<T>(element);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	/*
	   return front element
	 */
	T front(){
		if(isEmpty()){
			return 0;
			cout << "Queue Empty!" << endl;
		}
		return head->data;
	}

	/*
	   Deletion from front
	 */
	T dequeue(){
		if(isEmpty()){
			cout << "Queue Empty!" << endl;
			return 0;
		}
		T ans = head->data;
		Node<T>* temp = head;
		head= head->next;
		delete temp;
		size--;
		return ans;
	}
};
