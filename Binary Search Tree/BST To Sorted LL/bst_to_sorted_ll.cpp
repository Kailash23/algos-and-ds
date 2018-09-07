/*
   Code: BST to Sorted LL
   Given a BST, convert it into a sorted linked list. Return the head of LL.
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter root's data"<<endl;
	cin>>rootData;

	if(rootData == -1){
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		int leftData;
		cout<<"Enter left child's data"<<endl;
		cin>>leftData;

		if(leftData != -1){
			BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftData);
			front->left = leftChildNode;
			pendingNodes.push(leftChildNode);
		}

		int rightData;
		cout<<"Enter right child's data"<<endl;
		cin>>rightData;

		if(rightData != -1){
			BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightData);
			front->right = rightChildNode;
			pendingNodes.push(rightChildNode);
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
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	Node<int>* list = constructBST(root);
	cout<<endl;
	printLL(list);
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 */

/*
2 5 6 7 8 10
*/
