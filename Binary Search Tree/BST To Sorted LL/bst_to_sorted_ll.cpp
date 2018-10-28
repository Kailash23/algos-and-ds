/*
   Code: BST to Sorted LL
   Given a BST, convert it into a sorted linked list. Return the head of LL.
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

Node<int> *head = NULL;
Node<int> *tail = NULL;

void createLinkedList(int data){		// Time Complexity - O(n)
	Node<int>* newNode = new Node<int>(data);
	if(head == NULL && tail == NULL){
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = tail->next;
	}
}

void inOrderTraveral(BinaryTreeNode<int>* root){	// Time Complexity - O(n)
	if(root == NULL){
		return;
	}
	inOrderTraveral(root->left);
	createLinkedList(root->data);
	inOrderTraveral(root->right);
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    inOrderTraveral(root);
	return head;
}

void printLL(Node<int>* head){
	if(head == NULL){
		return;
	}
	while (head!=NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	Node<int>* list = constructBST(root);
	cout << endl;
	printLL(list);
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 */

/*
   2 5 6 7 8 10
 */
