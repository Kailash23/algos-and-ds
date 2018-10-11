/*
   Code : Height of Binary Tree

   Given a binary tree, find and return the height of given tree.

   Input format :
   Nodes in the level order form (separated by space). If any node does not have
   left or right child, take -1 in its place

   Output format :
   Height

   Constraints :
   1 <= N <= 10^5

   Sample Input :
   10 9 4 -1 -1 5 8 -1 6 -1 -1 3 -1 -1 -1

   Sample Output :
   5
 */

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

int height(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	int smallHeightLeft = 1 + height(root->left);
	int smallHeightRight = 1 + height(root->right);
	return max(smallHeightLeft, smallHeightRight);		// taking max of height from left and right sub-tree
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << "\nHeight of Binary Tree : " << height(root);
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

	Height of Binary Tree :4
 */

/*
	Alternative

	int height(BinaryTreeNode<int>* root){
		if(root == NULL) {
			return 0;
		}
		return 1 + max(height(root->left), height(root->right));    // Height will be the 1 + max among (height of left subtree) and (height right subtree).
	}
*/
