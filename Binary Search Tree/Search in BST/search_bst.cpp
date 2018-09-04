#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* getInput() {
	int rootData;
	cout<<"Enter root data : "<<endl;
	cin>>rootData;
	if(rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout<<"Enter left child of "<<front->data<<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}

		cout<<"Enter right child of "<<root->data<<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int>* root, int k) {

	if(root == NULL) {
		return NULL;
	}

	if(root->data == k) {
		return root;
	}

	if(root->data < k) {
		return searchInBST(root->right,k);
	}

	if(root->data > k) {
		return searchInBST(root->left,k);
	}
}

int main() {
	BinaryTreeNode<int>* root = getInput();
	int k = 6;
	root = searchInBST(root, k);
	if(root->data == k) {
		cout<<"Found";
	}
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   k = 6
   
   Found
 */
