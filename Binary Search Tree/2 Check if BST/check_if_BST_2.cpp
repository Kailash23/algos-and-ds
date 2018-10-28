/*
   Check if a Binary Tree is BST

   Given a binary tree with N number of nodes, check if that input tree is BST
   (Binary Search Tree) or not. If yes, return true, return false otherwise.

   Duplicate elements should be in right subtree.
 */

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

#include <queue>
#include <climits>

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

/*
   Function to check whether tree is BST or not.
   Time Complexity - O(n * h)
   We are calculating maximum of left node and minimum of right node, Therefore workdone is kn.
   And we are isBST on both left and right - 2T(n/2)

   				O							 O
			/		\						  \
		  O			  O						    O
		/	\		/	\						 \
	   O 	 O	   O	 O						   O
	   												\
		T(n) = kn + 2T(n/2)							  O
 ~Recurence Relation of Merge Sort					   \
			O(nlogn)			    				     O
														  \
		Height = log(n)						     		  	O
		Work = n * log(n)									 \
															   O

													T(n) = kn + T(n-1)
										 	~Recurence Relation of Bubble Sort
														O(n^2)
													Height = n
													Work = n * n

					So, Time Complexity = O (n * h)
					n -> no of nodes in tree
					h -> height of tree

		Generally, we can acheive O(n) time complexity in tree problems.
 */


int minimum(BinaryTreeNode<int>* root){
	if(root == NULL){		// Min of empty set (since there is no num) we can return positive infinity (means largest number you can store in an integer).
		return INT_MAX;
	}
	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MIN;		// Max of empty set (since there is no num) we can return negetive infinity (means smallest number you can store in an integer).
	}
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
	if(root == NULL){
		return true;		// It's a BST
	}
	int leftMax = maximum(root->left);		// Getting maximum of left subtree.
	int rightMin = minimum(root->right);	// Getting minimum of right subtree.
	bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right); //(true)- For any node its data should be greater than maximum data in its left
																												 //sub-tree and lesser than minimum in its right sub-tree. + its left and right subtree should be BST.
	return output;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << isBST(root);
}

/*
   Quick Input:
   8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
   1
 */
