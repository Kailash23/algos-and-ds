/*
   Level wise linkedlist

   Given a binary tree, write code to create a separate linked list for each level.
   You need to return the array which contains head of each level linked list.

   Input format :
   Elements in level order form (separated by space). If any node does not have
   left or right child, take -1 in its place.

   Output format : Each level linked list is printed in new line (elements separated
   by space).

   Sample Input :
   5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

   Sample Output :
   5
   6 10
   2 3
   9
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
using namespace std;

#include <queue>

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if(rootData == -1) {             // if data is -1 consider it as no child node.
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;               // queue used to input levelwise
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if(leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}

		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}
	}
	return root;
}

void printLinkedList(node<int>* head){
	while (head != NULL) {            // This will traverse to the last node
		cout << head->data << " ";
		head = head->next;
	}
}

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
	if(root == NULL) {              // If root is NULL return empty vector.
		vector<node<int>*> vec;
		return vec;
	}

	queue<BinaryTreeNode<int>*> pendingNodes;               // pendingNodes for tracking
	pendingNodes.push(root);

	queue<int> mainQueue;           // mainQueue to store data levelwise, where each level is separated by -1.

	while(pendingNodes.size() != 0) {
		int nodeCount = pendingNodes.size();        // nodeCount keeps track of count of nodes at each level eg nodeCount's
		                                            // value for below tree diag are :1 2 4 2 for respective levels 1 2 3 4.
		while(nodeCount > 0) {
			BinaryTreeNode<int>* front = pendingNodes.front();
			mainQueue.push(front->data);        // Storing front's data to the mainQueue
			pendingNodes.pop();
			if(front->left != NULL) {
				pendingNodes.push(front->left);     // Pushing front's left child to pendingNodes for next level execution.
			}
			if(front->right != NULL) {
				pendingNodes.push(front->right);    // Pushing front's right child to pendingNodes for next level execution.
			}
			nodeCount--;        // As we dequeue after extracting front we need to decrement nodeCount;
		}
		mainQueue.push(-1);     // When nodeCount == 0, which means that level is over we can insert -1 to mainQueue which acts as separater.
	}

	vector<node<int>*> listHeads;           // Vector for storing head of linked list formed at each level.

	while (mainQueue.size() != 0) {     // loop will end when mainQueue become empty
		node<int>* head = NULL;
		node<int>* tail = NULL;
		while (mainQueue.front() != -1) {
			int frontData = mainQueue.front();
			mainQueue.pop();
			node<int>* newNode = new node<int>(frontData);		// CREATING NODE OF LINKED LIST
			if(head == NULL) {      // for inserting for the first time head and tail point to same node.
				head = newNode;
				tail = newNode;
			} else {
				tail->next = newNode;   // Insertion at the end (tail) is acheived.
				tail = tail->next;
			}
		}
		mainQueue.pop();        // this dequeue is for poping -1, which terminates the above while loop.
		listHeads.push_back(head);      // head of linked list is pushed to vector of type node<int>
	}
	return listHeads;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << endl;
	vector<node<int>*> solution;
	solution = createLLForEachLevel(root);
	for(int i = 0; i < solution.size(); i++) {
		printLinkedList(solution[i]);
		cout << endl;
	}
	delete root;
}

/*
   Quick Input:
   1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
 */

/*
                                1
                            /		\
                          2			  3
                        /	\		/	\
                       4	 5	  6      7
                                /   \
                               8	 9

   1
   2 3
   4 5 6 7
   8 9

 */

/*
	Alternate Solution

	vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int>* root){
	    queue<BinaryTreeNode<int>*> q;
	    q.push(root);
	    int currentLevelRemaining = 1;
	    int nextLevelCount = 0;
	    vector<node<int>*> output;
	    node<int>* currentLevelHead = NULL;
	    node<int>* currentLevelTail = NULL;
	    while (!q.empty()) {
	        BinaryTreeNode<int>* first = q.front();
	        q.pop();
	        node<int>* newNode = new node<int>(first->data);
	        if (currentLevelHead == NULL) {
	            currentLevelHead = newNode;
	            currentLevelTail = newNode;
	        }
	        else {
	            currentLevelTail->next = newNode;
	            currentLevelTail = newNode;
	        }
	        if (first->left != NULL) {
	            q.push(first->left);
	            nextLevelCount++;
	        }
	        if (first->right != NULL) {
	            q.push(first->right);
	            nextLevelCount++;
	        }
	        currentLevelRemaining--;
	        if (currentLevelRemaining == 0) {
	            output.push_back(currentLevelHead);
	            currentLevelHead = NULL;
	            currentLevelTail = NULL;
	            currentLevelRemaining = nextLevelCount;
	            nextLevelCount = 0;
	        }
	    }
	    return output;
	}
 */
