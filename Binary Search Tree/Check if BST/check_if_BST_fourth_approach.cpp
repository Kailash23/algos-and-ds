/*
   Check if a Binary Tree is BST

   Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.

   Duplicate elements should be in right subtree.
 */

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <climits>
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

/*
   Function to check whether tree is BST or not.
   Time Complexity - O(n)
   We are doing only constant work like comparision, making and assigning class object.
   And we are calling recursion on both left and right - 2T(n/2)

		T(n) = 2T(n/2) + k
		=>	O(n)
 */

bool isBST(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
	if(root == NULL){
		return true;
	}
	if(root->data < min || root->data >= max){
		return false;
	}
	bool isLeftOk = isBST(root->left, min, root->data);
	bool isRightOk = isBST(root->right,root->data, max);
	return isLeftOk && isRightOk;
}


int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	bool res;
	res = isBST(root);
	if(res){
		cout<<"It's BST";
	} else {
		cout<<"It's not BST";
	}
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   It's BST

   8 5 10 2 1 -1 -1 -1 -1 -1 7 -1 -1
   It's
 */
