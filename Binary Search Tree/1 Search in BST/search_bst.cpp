#include <iostream>
#include "BinaryTreeNode.h"
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

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int>* root, int k) {
	if(root == NULL) {
		return NULL;
	}
	if(root->data == k) {
		return root;
	}
	if(root->data < k) {
		return searchInBST(root->right, k);		// k is greater than root element ie k must be on right
	}
	if(root->data > k) {
		return searchInBST(root->left, k);		// k is less than root element ie k must be on left
	}
}

int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	int k = 6;
	root = searchInBST(root, k);
	if(root != NULL){
		if(k == root->data){
			cout << "Found!" << endl;
		}
	} else {
		cout << "Not found!" << endl;
	}
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   k = 6

   Found
 */
