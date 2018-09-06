/*
   Construct BST from a Sorted Array

   Given a sorted integer array A of size n which contains all unique elements.
   You need to construct a balanced BST from this input array. Return the root of constructed BST.
 */

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

BinaryTreeNode<int>* constructTree(int *input, int n) {

}




int main() {
	BinaryTreeNode<int>* root = getInput();
}


/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

 */
