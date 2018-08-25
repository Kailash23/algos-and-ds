/*
   Length of LL

   Given a linked list, find and return the length of input LL. Do it iteratively.
   Input format :
   Linked list elements (separated by space and terminated by -1)
 */

class Node {
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
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

/*
   Function that will return the number of nodes in a linked list
 */
int length(Node *head) {
	Node* temp = head;
	int len = 0;
	while(temp != NULL) {
		len++;
		temp = temp->next;
	}
	return len;
}

int main(){
	Node* head = takeInput_Better();
	cout<< length(head) <<endl;
}
