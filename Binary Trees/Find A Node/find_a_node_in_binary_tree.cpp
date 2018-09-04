/*
   Code : Find a node

   Given a Binary Tree and an integer x, check if node with data x is present in
   the input binary tree or not. Return true or false.
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout<<"Enter root data"<<endl;
	cin>>rootData;
	if(rootData == -1) {             // if data is -1 consider it as no child node.
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;               // queue used to input levelwise
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout<< "Enter left child of "<<front->data <<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}

		cout<< "Enter right child of "<< front->data <<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);               // Push child node for inputing there child nodes.
		}
	}
	return root;
}

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
	if(root == NULL) {
		return false;
	}
	if(root->data == x) {
		return true;
	}
	return isNodePresent(root->left,x) || isNodePresent(root->right,x);
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout<<endl;
	int x;
	cin>>x;
	if(isNodePresent(root, x)) {
		cout<< "Present!" <<endl;
	} else {
		cout<< "Not Present!" <<endl;
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

	5
	Present!
 */
